#ifndef USER_H
#define USER_H

#include <string>
#include <atomic>

class User {
public:
    using IdType = unsigned long;

    explicit User(std::string username);
    ~User() = default;

    IdType id() const noexcept;
    const std::string& username() const noexcept;

    // Equality by id
    bool operator==(const User& other) const noexcept;
    bool operator!=(const User& other) const noexcept;

private:
    static std::atomic<IdType> s_nextId;
    IdType m_id;
    std::string m_username;
};

#endif // USER_H
