#include <iostream>
#include <stdexcept>
#include <vector>

#include "message.h"
#include "user.h"

/*
 * \brief fills the file from the vector with users or messages
 *
 * \param[in] file_name path to the file with users
 * \param[out] msgs a vector to be filled
 */
template <typename T>
static void save_all_into_file(
    std::string const& file_name, std::vector<T> const& objs)
{
    std::ofstream out(file_name, std::ios::out);
    if (out.is_open()) {
        for (auto& obj : objs) {
            out << obj << std::endl;
        }
        out.close();
        return;
    }
    throw std::runtime_error("error: could not open this file " + file_name);
}

/*
 * read file and fills the vector
 *
 * \param[in] file_name path to the file with users or messages
 * \param[out] msgs a vector to be filled
 */
template <typename T>
static void read_all_from_file(
    std::string const& file_name, std::vector<T>& objs)
{
    std::fstream in(file_name, std::ios::in);
    if (!in.is_open()) {
        std::cout << "why" << std::endl;
        throw std::runtime_error(
            "error: could not open this file " + file_name);
        return;
    }
    in.seekg(0, std::ios_base::beg);
    T new_obj("", "", "");
    while (in >> new_obj) {
        objs.push_back(new_obj);
    }
    in.close();
}

int main()
try {
    std::vector<User> users;
    std::vector<Message> messages;
    // заполняем вектор пользователями
    read_all_from_file("users.txt", users);
    for (auto& user : users) {
        std::cout << user << std::endl;
    }
    // сохраняем пользователей в другой файл
    save_all_into_file("users1.txt", users);

    // messages
    std::cout << "messages" << std::endl;
    read_all_from_file("msgs.txt", messages);
    for (auto& msg : messages) {
        std::cout << msg << std::endl;
    }
    // сохраняем сообщение в другой файл
    save_all_into_file("msgs2.txt", messages);
    return 0;
} catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
}
