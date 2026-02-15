#include "catch_amalgamated.hpp"
#include "Message.h"
#include "User.h"
#include <memory>

// Test: il messaggio memorizza correttamente sender, receiver e testo
TEST_CASE("Message stores sender/receiver/text", "[Message]") {
    auto alice = std::make_shared<User>("Alice");
    auto bob   = std::make_shared<User>("Bob");

    Message msg(alice, bob, "Hello");

    REQUIRE(msg.sender()->username() == "Alice");
    REQUIRE(msg.receiver()->username() == "Bob");
    REQUIRE(msg.text() == "Hello");
}

// Test: formattazione del timestamp non è vuota
TEST_CASE("Formatted timestamp is not empty", "[Message]") {
    auto alice = std::make_shared<User>("Alice");
    auto bob   = std::make_shared<User>("Bob");

    Message msg(alice, bob, "Test");

    REQUIRE_FALSE(msg.formattedTimestamp().empty());
}