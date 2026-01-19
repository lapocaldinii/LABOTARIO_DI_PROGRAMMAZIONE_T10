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

    // ritorna la chat esistente se esiste oppure ne crea una nuova
    std::shared_ptr<Chat> getOrCreateChat(const std::shared_ptr<User>& u1,
                                          const std::shared_ptr<User>& u2);

    // cerca la chat
    std::shared_ptr<Chat> findChat(const std::shared_ptr<User>& u1,
                                   const std::shared_ptr<User>& u2) const;

    // lista delle chat
    std::vector<std::shared_ptr<Chat>> allChats() const;

    // stampa le chat
    void printAll(std::ostream& out) const;

private:
    mutable std::mutex m_mutex;
    std::vector<std::shared_ptr<Chat>> m_chats;
};

#endif // CHATREGISTRY_H
