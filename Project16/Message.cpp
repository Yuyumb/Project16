#include "Message.h"
#include <fstream>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

Message::Message(const std::string& text, const std::string& sender, const std::string& receiver)
    : _text(text), _sender(sender), _receiver(receiver) {}

void Message::save(const fs::path& filename) const {
    std::ofstream file(filename, std::ios::trunc);
    if (file.is_open()) {
        file << _text << '\n' << _sender << '\n' << _receiver;
        file.close();
        fs::permissions(filename, fs::perms::owner_read | fs::perms::owner_write);
    }
    else {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
    }
}

void Message::load(const fs::path& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::getline(file, _text);
        std::getline(file, _sender);
        std::getline(file, _receiver);
        file.close();
    }
    else {
        std::cerr << "Failed to open file for reading: " << filename << std::endl;
    }
}

void Message::print() const {
    std::cout << "Text: " << _text << std::endl;
    std::cout << "Sender: " << _sender << std::endl;
    std::cout << "Receiver: " << _receiver << std::endl;
}