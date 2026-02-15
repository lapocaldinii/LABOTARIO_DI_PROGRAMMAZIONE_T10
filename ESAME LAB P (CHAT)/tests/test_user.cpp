#include "catch_amalgamated.hpp"
#include "User.h"

// Test: ogni User riceve un ID diverso
TEST_CASE("User creation assigns unique IDs", "[User]") {
    User u1("Alice");
    User u2("Bob");

    REQUIRE(u1.id() != u2.id());
}

// Test: lo username viene salvato correttamente
TEST_CASE("Username is stored correctly", "[User]") {
    User u("Charlie");

    REQUIRE(u.username() == "Charlie");
}

// Test: uguaglianza basata su ID
TEST_CASE("Equality works by ID", "[User]") {
    User u1("Dave");
    User u2("Eve");

    REQUIRE(u1 != u2);
}