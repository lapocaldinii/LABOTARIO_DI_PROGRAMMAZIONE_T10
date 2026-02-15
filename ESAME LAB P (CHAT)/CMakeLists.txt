cmake_minimum_required(VERSION 3.31)
project(ESAME_LAB_P__CHAT_)

set(CMAKE_CXX_STANDARD 20)

add_executable(ESAME_LAB_P__CHAT_ main.cpp
        User.cpp
        User.h
        Message.cpp
        Message.h
        Chat.cpp
        Chat.h
        ChatRegistry.cpp
        ChatRegistry.h)