#ifndef CHATREGISTRY_H
#define CHATREGISTRY_H

#include "Chat.h"

#include <memory>
#include <vector>
#include <mutex>
#include <optional>

class ChatRegistry {
public:
    ChatRegistry() = default;
    ~ChatRegistry() = default;

    // returns existing chat between u1 and u2 or creates a new one
    std::shared_ptr<Chat> getOrCreateChat(const std::shared_ptr<User>& u1,
                                          const std::shared_ptr<User>& u2);

    // find chat if exists
    std::shared_ptr<Chat> findChat(const std::shared_ptr<User>& u1,
                                   const std::shared_ptr<User>& u2) const;

    // list all chats (copy)
    std::vector<std::shared_ptr<Chat>> allChats() const;

    // print all chats
    void printAll(std::ostream& out) const;

private:
    mutable std::mutex m_mutex;
    std::vector<std::shared_ptr<Chat>> m_chats;
};

#endif // CHATREGISTRY_H
