#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    using IdType = unsigned long;

    explicit User(std::string username);
    ~User() = default;

    IdType id() const noexcept;
    const std::string& username() const noexcept;

    bool operator==(const User& other) const noexcept;
    bool operator!=(const User& other) const noexcept;

private:
    static IdType s_nextId;   // NON atomic
    IdType m_id;
    std::string m_username;
};

#endif // USER_H
