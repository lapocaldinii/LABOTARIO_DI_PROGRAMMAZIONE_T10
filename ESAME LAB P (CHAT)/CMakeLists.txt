cmake_minimum_required(VERSION 3.31)
project(ESAME_LAB_P__CHAT_)

set(CMAKE_CXX_STANDARD 20)

# =======================
# ESEGUIBILE PRINCIPALE
# =======================
add_executable(ESAME_LAB_P__CHAT_
        main.cpp
        User.cpp User.h
        Message.cpp Message.h
        Chat.cpp Chat.h
        ChatRegistry.cpp ChatRegistry.h
)

# =======================
# ESEGUIBILE TEST (Catch2)
# =======================
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/catch_amalgamated.hpp")
    file(GLOB TEST_SOURCES "tests/*.cpp")

    # Aggiungi catch_amalgamated.cpp tra i sorgenti!
    add_executable(tests
            tests/catch_amalgamated.cpp
            ${TEST_SOURCES}
            User.cpp User.h
            Message.cpp Message.h
            Chat.cpp Chat.h
            ChatRegistry.cpp ChatRegistry.h
    )

    target_include_directories(tests PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}
            ${CMAKE_CURRENT_SOURCE_DIR}/tests
    )

    enable_testing()
    add_test(NAME all_tests COMMAND tests)
endif()
