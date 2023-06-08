#pragma once

#include <fstream>
#include <string>

class Message {
public:
    Message(const std::string& text, const std::string& sender,
        const std::string& receiver)
        : text_(text)
        , sender_(sender)
        , receiver_(receiver)
    {
    }

    Message() = default;

    friend std::fstream& operator>>(std::fstream& is, Message& obj);
    friend std::ostream& operator<<(std::ostream& os, const Message& obj);

private:
    std::string text_;
    std::string sender_;
    std::string receiver_;
};
