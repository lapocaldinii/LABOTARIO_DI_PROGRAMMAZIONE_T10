#include "catch_amalgamated.hpp"
#include "ChatRegistry.h"
#include <memory>

// Test: il registro crea una nuova chat
TEST_CASE("Registry creates new chat", "[ChatRegistry]") {
    ChatRegistry reg;

    auto alice = std::make_shared<User>("Alice");
    auto bob   = std::make_shared<User>("Bob");

    auto chat = reg.getOrCreateChat(alice, bob);

    REQUIRE(chat != nullptr);
    REQUIRE(reg.allChats().size() == 1);
}

// Test: il registro restituisce la stessa chat esistente
TEST_CASE("Registry returns existing chat", "[ChatRegistry]") {
    ChatRegistry reg;

    auto alice = std::make_shared<User>("Alice");
    auto bob   = std::make_shared<User>("Bob");

    auto c1 = reg.getOrCreateChat(alice, bob);
    auto c2 = reg.getOrCreateChat(bob, alice);

    REQUIRE(c1 == c2);
    REQUIRE(reg.allChats().size() == 1);
}

// Test: Ricerca chat funziona correttamente
TEST_CASE("FindChat works correctly", "[ChatRegistry]") {
    ChatRegistry reg;

    auto alice = std::make_shared<User>("Alice");
    auto bob   = std::make_shared<User>("Bob");

    reg.getOrCreateChat(alice, bob);
    auto found = reg.findChat(alice, bob);

    REQUIRE(found != nullptr);
}