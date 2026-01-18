#include "User.h"

#include <utility>

std::atomic<User::IdType> User::s_nextId{1};

User::User(std::string username)
    : m_id(s_nextId.fetch_add(1, std::memory_order_relaxed)),
      m_username(std::move(username))
{}

User::IdType User::id() const noexcept { return m_id; }
const std::string& User::username() const noexcept { return m_username; }

bool User::operator==(const User& other) const noexcept { return m_id == other.m_id; }
bool User::operator!=(const User& other) const noexcept { return !(*this == other); }
