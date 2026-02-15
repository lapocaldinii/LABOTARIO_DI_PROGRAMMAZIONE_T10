#ifndef CHAT_H
#define CHAT_H

#include "User.h"
#include "Message.h"

#include <memory>
#include <vector>
#include <string>

class Chat {
public:
    Chat(std::shared_ptr<User> a, std::shared_ptr<User> b);
    ~Chat() = default;

    Chat(const Chat&) = delete;
    Chat& operator=(const Chat&) = delete;

    void sendMessage(std::shared_ptr<User> sender, const std::string& text);

    std::vector<Message> messages() const;

    void print(std::ostream& out) const;

    bool involves(const std::shared_ptr<User>& u1,
                  const std::shared_ptr<User>& u2) const noexcept;

    std::pair<std::shared_ptr<User>, std::shared_ptr<User>> participants() const noexcept;

private:
    std::shared_ptr<User> m_userA;
    std::shared_ptr<User> m_userB;
    std::vector<Message> m_messages;

    std::shared_ptr<User> otherOf(const std::shared_ptr<User>& sender) const;
};

#endif // CHAT_H
