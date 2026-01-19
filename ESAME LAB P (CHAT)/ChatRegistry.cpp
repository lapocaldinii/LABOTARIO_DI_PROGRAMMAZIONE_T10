#include "ChatRegistry.h"

std::shared_ptr<Chat> ChatRegistry::getOrCreateChat(const std::shared_ptr<User>& u1,
                                                   const std::shared_ptr<User>& u2)
{
    if (!u1 || !u2) throw std::invalid_argument("Users must be non-null");
    if (u1->id() == u2->id()) throw std::invalid_argument("Cannot create chat with same user twice");

    // controlla se la chat esiste e poi ne crea una
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        for (auto& c : m_chats) {
            if (c->involves(u1, u2)) return c;
        }

        auto newChat = std::make_shared<Chat>(u1, u2);
        m_chats.push_back(newChat);
        return newChat;
    }
}

std::shared_ptr<Chat> ChatRegistry::findChat(const std::shared_ptr<User>& u1,
                                             const std::shared_ptr<User>& u2) const
{
    std::lock_guard<std::mutex> lock(m_mutex);
    for (auto& c : m_chats) {
        if (c->involves(u1, u2)) return c;
    }
    return nullptr;
}

std::vector<std::shared_ptr<Chat>> ChatRegistry::allChats() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_chats; // copy vector of shared_ptr
}

void ChatRegistry::printAll(std::ostream& out) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    out << "ChatRegistry: " << m_chats.size() << " chat(s)\n";
    for (const auto& c : m_chats) {
        c->print(out);
    }
}
