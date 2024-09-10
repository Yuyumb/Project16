#pragma once
#include <string>
#include <filesystem>

class Message
{
private:
	std::string _text;
	std::string _sender;
	std::string _receiver;
public:
	Message() = default;
	Message(const std::string& text, const std::string& sender, const std::string& receiver);

	void save(const std::filesystem::path& filename) const;
	void load(const std::filesystem::path& filename);
	void print() const;
};