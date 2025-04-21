#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sstream>
#include <iomanip>
#include <cstdlib>

class contact
{
    public:
        void set_first_name(std::string name);
        void get_first_name();
        void set_last_name(std::string name);
        void get_last_name();
        void set_nickname_name(std::string name);
        void get_nickname_name();
        void set_darkest_secret(std::string name);
        void get_darkest_secret();
        void set_phone_number(std::string name);
        void get_phone_number();
        void display_info(std::string string);
        void display_all_info(int track);

    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string darkest_secret;
        std::string phone_number;
};

#endif