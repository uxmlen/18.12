#pragma once

#include <fstream>
#include <string>

class User {
public:
    User(const std::string& name, const std::string& login,
        const std::string& password)
        : name_(name)
        , login_(login)
        , password_(login)
    {
    }

    friend std::fstream& operator>>(std::fstream& is, User& obj);
    friend std::ostream& operator<<(std::ostream& os, const User& obj);

private:
    std::string name_;
    std::string login_;
    std::string password_;
};
