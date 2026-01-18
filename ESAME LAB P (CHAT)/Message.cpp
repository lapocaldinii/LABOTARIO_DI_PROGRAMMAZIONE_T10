#include "Message.h"
#include <iomanip>
#include <sstream>
#include <ctime>

Message::Message(std::shared_ptr<User> sender,
                 std::shared_ptr<User> receiver,
                 std::string text,
                 TimePoint timestamp)
    : m_sender(std::move(sender)),
      m_receiver(std::move(receiver)),
      m_text(std::move(text)),
      m_timestamp(timestamp)
{}

std::shared_ptr<User> Message::sender() const noexcept { return m_sender; }
std::shared_ptr<User> Message::receiver() const noexcept { return m_receiver; }
const std::string& Message::text() const noexcept { return m_text; }
Message::TimePoint Message::timestamp() const noexcept { return m_timestamp; }

std::string Message::formattedTimestamp() const {
    using namespace std::chrono;
    std::time_t t = system_clock::to_time_t(m_timestamp);
    std::tm tm{};
#if defined(_WIN32) || defined(_WIN64)
    localtime_s(&tm, &t);
#else
    localtime_r(&t, &tm);
#endif
    std::ostringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}
