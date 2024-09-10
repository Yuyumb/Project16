#pragma once
#include <string>
#include <filesystem>

class User
{
private:
	std::string _name;
	std::string _login;
	std::string _pass;
public:
	User() = default;
	User(const std::string& name, const std::string& login, const std::string& pass);

	void save(const std::filesystem::path& filename) const;
	void load(const std::filesystem::path& filename);
	void print() const;
};