


#include "User.h"
#include "ChatRegistry.h"
#include <iostream>
#include <memory>

int main() {

    // Create users (managed by shared_ptr)
    auto alice = std::make_shared<User>("Alice");
    auto bob   = std::make_shared<User>("Bob");
    auto carlo = std::make_shared<User>("Carlo");

    ChatRegistry registry;

    // Create or retrieve chats
    auto chatAB = registry.getOrCreateChat(alice, bob);
    chatAB->sendMessage(alice, "Ciao Bob! Come va?");
    chatAB->sendMessage(bob, "Bene Alice, grazie! Tu?");
    chatAB->sendMessage(alice, "Tutto a posto.");

    auto chatAC = registry.getOrCreateChat(alice, carlo);
    chatAC->sendMessage(carlo, "Hey Alice, ci vediamo stasera?");
    chatAC->sendMessage(alice, "Sì, alle 20 va bene.");

    // Requesting existing chat again (should not create duplicate)
    auto chatAB_again = registry.getOrCreateChat(bob, alice);
    chatAB_again->sendMessage(bob, "Ti mando la posizione.");

    // Print all chats
    registry.printAll(std::cout);

    return 0;
}

