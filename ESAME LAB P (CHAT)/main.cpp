

#include "User.h"
#include "Chat.h"

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

struct ChatEntry {
    std::string userA;
    std::string userB;
    std::shared_ptr<User> u1;
    std::shared_ptr<User> u2;
    std::shared_ptr<Chat> chat;
};

// normalizza i nomi (Alice Bob == Bob Alice)
std::pair<std::string, std::string> normalize(const std::string& a,
                                               const std::string& b) {
    return (a < b) ? std::make_pair(a, b) : std::make_pair(b, a);
}

void chatSession(const ChatEntry& entry) {
    std::string senderName;
    std::string message;

    std::cout << "\nEntrato nella chat tra "
              << entry.userA << " e " << entry.userB << "\n";
    std::cout << "Scrivi /exit per tornare al menu\n";

    while (true) {
        std::cout << "\n-----------------------------\n";
        entry.chat->print(std::cout);

        std::cout << "\nChi scrive (" << entry.userA
                  << "/" << entry.userB << "): ";
        std::getline(std::cin, senderName);

        std::shared_ptr<User> sender = nullptr;

        if (senderName == entry.userA)
            sender = entry.u1;
        else if (senderName == entry.userB)
            sender = entry.u2;
        else if (senderName == "/exit")
            return;
        else {
            std::cout << "Utente non valido.\n";
            continue;
        }

        std::cout << "Messaggio: ";
        std::getline(std::cin, message);

        if (message == "/exit") {
            std::cout << "Uscita dalla chat.\n";
            return;
        }

        try {
            entry.chat->sendMessage(sender, message);
        } catch (const std::exception& e) {
            std::cout << "Errore: " << e.what() << "\n";
        }
    }
}

int main() {
    std::vector<ChatEntry> chats;
    const size_t MAX_CHATS = 5;

    while (true) {
        std::cout << "\n=== MENU PRINCIPALE ===\n";
        std::cout << "1) Crea nuova chat\n";
        std::cout << "2) Entra in una chat\n";
        std::cout << "3) Lista chat\n";
        std::cout << "4) Esci\n";
        std::cout << "Scelta: ";

        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "1") {
            if (chats.size() >= MAX_CHATS) {
                std::cout << "Limite massimo di chat raggiunto.\n";
                continue;
            }

            std::string a, b;
            std::cout << "Nome primo utente: ";
            std::getline(std::cin, a);
            std::cout << "Nome secondo utente: ";
            std::getline(std::cin, b);

            if (a == b) {
                std::cout << "I due utenti devono essere diversi.\n";
                continue;
            }

            auto key = normalize(a, b);

            bool exists = false;
            for (const auto& c : chats) {
                if (normalize(c.userA, c.userB) == key) {
                    exists = true;
                    break;
                }
            }

            if (exists) {
                std::cout << "Chat già esistente.\n";
                continue;
            }

            ChatEntry entry;
            entry.userA = key.first;
            entry.userB = key.second;
            entry.u1 = std::make_shared<User>(entry.userA);
            entry.u2 = std::make_shared<User>(entry.userB);
            entry.chat = std::make_shared<Chat>(entry.u1, entry.u2);

            chats.push_back(entry);
            std::cout << "Chat creata con successo.\n";
        }
        else if (choice == "2") {
            if (chats.empty()) {
                std::cout << "Nessuna chat disponibile.\n";
                continue;
            }

            std::cout << "Chat disponibili:\n";
            for (size_t i = 0; i < chats.size(); ++i) {
                std::cout << i + 1 << ") "
                          << chats[i].userA << " - "
                          << chats[i].userB << "\n";
            }

            std::cout << "Seleziona chat: ";
            std::string indexStr;
            std::getline(std::cin, indexStr);

            size_t index = std::stoi(indexStr);
            if (index == 0 || index > chats.size()) {
                std::cout << "Scelta non valida.\n";
                continue;
            }

            chatSession(chats[index - 1]);
        }
        else if (choice == "3") {
            if (chats.empty()) {
                std::cout << "Nessuna chat creata.\n";
            } else {
                for (size_t i = 0; i < chats.size(); ++i) {
                    std::cout << i + 1 << ") "
                              << chats[i].userA << " - "
                              << chats[i].userB << "\n";
                }
            }
        }
        else if (choice == "4") {
            std::cout << "Chiusura programma.\n";
            break;
        }
        else {
            std::cout << "Scelta non valida.\n";
        }
    }

    return 0;
}
