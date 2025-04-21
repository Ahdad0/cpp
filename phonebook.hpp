#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "contact.hpp"

class Phonebook
{
    private:
        contact contacts[8];
        int index;
        int track;

    public:
        int last;
        Phonebook()
        {
            index = 0;
            track = 0;
            last = 0;
        }
        void add_contact(const contact &obj);
        void display_contact(int num);
        void display_contacts();
};

#endif