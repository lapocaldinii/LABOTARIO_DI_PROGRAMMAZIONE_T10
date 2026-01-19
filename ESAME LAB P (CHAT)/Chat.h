#ifndef CHAT_H
#define CHAT_H

#include "User.h"
#include "Message.h"

#include <memory>
#include <vector>
#include <mutex>
#include <string>

class Chat {
public:
    Chat(std::shared_ptr<User> a, std::shared_ptr<User> b);
    ~Chat() = default;


    Chat(const Chat&) = delete;
    Chat& operator=(const Chat&) = delete;

    // add a message from sender to the other participant
    void sendMessage(std::shared_ptr<User> sender, const std::string& text);

    // arichivio messaggi
    std::vector<Message> messages() const;

    // scrive la chat
    void print(std::ostream& out) const;

    // controlla chi è coinvolto nella chat (user)
    bool involves(const std::shared_ptr<User>& u1, const std::shared_ptr<User>& u2) const noexcept;

    std::pair<std::shared_ptr<User>, std::shared_ptr<User>> participants() const noexcept;

private:
    std::shared_ptr<User> m_userA;
    std::shared_ptr<User> m_userB;
    mutable std::mutex m_mutex;
    std::vector<Message> m_messages;

    // determina un partecipante grazie al puntatore del mandante di un messaggio
    std::shared_ptr<User> otherOf(const std::shared_ptr<User>& sender) const;
};

#endif // CHAT_H
