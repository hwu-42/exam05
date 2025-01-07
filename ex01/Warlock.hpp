#pragma once
#include <iostream>
#include <map>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
    private:
        std::string name;
        std::string title;
        std::map <std::string, ASpell*> spells;
    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();
        std::string const &getName() const;
        std::string const &getTitle() const;
        void setTitle(std::string const &title);
        void introduce() const;
        void learnSpell(ASpell *aspell);
        void forgetSpell(std::string const &name);
        void launchSpell(std::string const &name, ATarget &atarget);
};