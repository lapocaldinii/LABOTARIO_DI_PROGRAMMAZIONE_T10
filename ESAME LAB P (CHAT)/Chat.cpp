#include "Chat.h"
#include <iostream>
#include <algorithm>

Chat::Chat(std::shared_ptr<User> a, std::shared_ptr<User> b)
    : m_userA(std::move(a)), m_userB(std::move(b))
{

    if (m_userA->id() == m_userB->id()) {
        throw std::invalid_argument("Chat requires two distinct users");
    }
}

std::shared_ptr<User> Chat::otherOf(const std::shared_ptr<User>& sender) const {
    if (!sender) return nullptr;
    if (sender->id() == m_userA->id()) return m_userB;
    if (sender->id() == m_userB->id()) return m_userA;
    return nullptr;
}

void Chat::sendMessage(std::shared_ptr<User> sender, const std::string& text) {
    auto receiver = otherOf(sender);
    if (!receiver) {
        throw std::invalid_argument("Sender is not part of this chat");
    }
    Message msg(std::move(sender), std::move(receiver), text);
    std::lock_guard<std::mutex> lock(m_mutex);
    m_messages.push_back(std::move(msg));
}

std::vector<Message> Chat::messages() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_messages; // copy
}

void Chat::print(std::ostream& out) const {
    out << "Chat between [" << m_userA->username()
        << " (id=" << m_userA->id() << ")] and ["
        << m_userB->username()
        << " (id=" << m_userB->id() << ")]\n";
    std::lock_guard<std::mutex> lock(m_mutex);
    for (const auto& m : m_messages) {
        out << "[" << m.formattedTimestamp() << "] "
            << m.sender()->username() << " -> "
            << m.receiver()->username() << ": "
            << m.text() << "\n";
    }
    out << "---- end chat ----\n";
}

bool Chat::involves(const std::shared_ptr<User>& u1, const std::shared_ptr<User>& u2) const noexcept {
    if (!u1 || !u2) return false;
    auto id1 = u1->id();
    auto id2 = u2->id();
    auto a = m_userA->id();
    auto b = m_userB->id();
    return (id1 == a && id2 == b) || (id1 == b && id2 == a);
}

std::pair<std::shared_ptr<User>, std::shared_ptr<User>> Chat::participants() const noexcept {
    return {m_userA, m_userB};
}
