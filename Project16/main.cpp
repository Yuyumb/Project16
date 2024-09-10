#include "User.h"
#include "Message.h"
#include <iostream>
#include <filesystem>

int main() {
    User user("Anna Bell", "annabell", "password123");
    user.save("user.txt");

    Message message("Hello, Mary!", "annabell", "marybell");
    message.save("message.txt");

    User loadedUser;
    loadedUser.load("user.txt");
    loadedUser.print();

    Message loadedMessage;
    loadedMessage.load("message.txt");
    loadedMessage.print();

    return 0;
}