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

    // Non-copyable, non-movable (to simplify ownership semantics)
    Chat(const Chat&) = delete;
    Chat& operator=(const Chat&) = delete;

    // add a message from sender to the other participant
    void sendMessage(std::shared_ptr<User> sender, const std::string& text);

    // all messages (thread-safe copy)
    std::vector<Message> messages() const;

    // print to ostream
    void print(std::ostream& out) const;

    // check whether this chat involves the two users (order-free)
    bool involves(const std::shared_ptr<User>& u1, const std::shared_ptr<User>& u2) const noexcept;

    std::pair<std::shared_ptr<User>, std::shared_ptr<User>> participants() const noexcept;

private:
    std::shared_ptr<User> m_userA;
    std::shared_ptr<User> m_userB;
    mutable std::mutex m_mutex;
    std::vector<Message> m_messages;

    // helper to determine other participant given sender
    std::shared_ptr<User> otherOf(const std::shared_ptr<User>& sender) const;
};

#endif // CHAT_H
