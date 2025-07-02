#pragma once

#include <iostream>

class Weapon
{
    public:
        Weapon(std::string we);
        // ~Weapon();
        const std::string& getType();
        void setType(std::string input);

    private:
        std::string type;
};
