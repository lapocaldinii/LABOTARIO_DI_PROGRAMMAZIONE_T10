#ifndef CHATREGISTRY_H
#define CHATREGISTRY_H

#include "Chat.h"

#include <memory>
#include <vector>

class ChatRegistry {
public:
    ChatRegistry() = default;
    ~ChatRegistry() = default;

    std::shared_ptr<Chat> getOrCreateChat(const std::shared_ptr<User>& u1,
                                          const std::shared_ptr<User>& u2);

    std::shared_ptr<Chat> findChat(const std::shared_ptr<User>& u1,
                                   const std::shared_ptr<User>& u2) const;

    std::vector<std::shared_ptr<Chat>> allChats() const;

    void printAll(std::ostream& out) const;

private:
    std::vector<std::shared_ptr<Chat>> m_chats;
};

#endif // CHATREGISTRY_H
