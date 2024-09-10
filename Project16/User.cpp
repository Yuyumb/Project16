#include "User.h"
#include <fstream>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

User::User(const std::string& name, const std::string& login, const std::string& pass)
    : _name(name), _login(login), _pass(pass) {}

void User::save(const fs::path& filename) const {
    std::ofstream file(filename, std::ios::trunc);
    if (file.is_open()) {
        file << _name << '\n' << _login << '\n' << _pass;
        file.close();
        fs::permissions(filename, fs::perms::owner_read | fs::perms::owner_write);
    }
    else {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
    }
}

void User::load(const fs::path& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::getline(file, _name);
        std::getline(file, _login);
        std::getline(file, _pass);
        file.close();
    }
    else {
        std::cerr << "Failed to open file for reading: " << filename << std::endl;
    }
}

void User::print() const {
    std::cout << "Name: " << _name << std::endl;
    std::cout << "Login: " << _login << std::endl;
    std::cout << "Password: " << _pass << std::endl;
}