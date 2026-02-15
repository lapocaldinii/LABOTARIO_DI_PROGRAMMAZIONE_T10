#include "catch_amalgamated.hpp"
#include "Chat.h"
#include <memory>

// Test: una chat richiede due utenti distinti
TEST_CASE("Chat requires two distinct users", "[Chat]") {
    auto alice = std::make_shared<User>("Alice");
    REQUIRE_THROWS(Chat(alice, alice));
}

// Test: invio di un messaggio aggiunge alla cronologia
TEST_CASE("Sending message adds to history", "[Chat]") {
    auto alice = std::make_shared<User>("Alice");
    auto bob   = std::make_shared<User>("Bob");

    Chat chat(alice, bob);
    chat.sendMessage(alice, "Hello Bob");

    auto msgs = chat.messages();

    REQUIRE(msgs.size() == 1);
    REQUIRE(msgs[0].text() == "Hello Bob");
}

// Test: il mittente deve appartenere alla chat
TEST_CASE("Sender must belong to chat", "[Chat]") {
    auto alice = std::make_shared<User>("Alice");
    auto bob   = std::make_shared<User>("Bob");
    auto eve   = std::make_shared<User>("Eve");

    Chat chat(alice, bob);
    REQUIRE_THROWS(chat.sendMessage(eve, "Intrusion"));
}