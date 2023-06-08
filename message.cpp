#include "message.h"

std::fstream& operator>>(std::fstream& is, Message& obj)
{
    is >> obj.text_;
    is >> obj.sender_;
    is >> obj.receiver_;

    return is;
}

std::ostream& operator<<(std::ostream& os, const Message& obj)
{
    os << obj.text_;
    os << ' ';
    os << obj.sender_;
    os << ' ';
    os << obj.receiver_;

    return os;
}
