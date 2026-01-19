#ifndef MESSAGE_H
#define MESSAGE_H

#include <chrono>
#include <memory>
#include <string>
#include "User.h"

class Message {
public:
    using TimePoint = std::chrono::system_clock::time_point;

    Message(std::shared_ptr<User> sender,
            std::shared_ptr<User> receiver,
            std::string text,
            TimePoint timestamp = std::chrono::system_clock::now());

    ~Message() = default;

    std::shared_ptr<User> sender() const noexcept;
    std::shared_ptr<User> receiver() const noexcept;
    const std::string& text() const noexcept;
    TimePoint timestamp() const noexcept;

    // timestamp
    std::string formattedTimestamp() const;

private:
    std::shared_ptr<User> m_sender;
    std::shared_ptr<User> m_receiver;
    std::string m_text;
    TimePoint m_timestamp;
};

#endif // MESSAGE_H
