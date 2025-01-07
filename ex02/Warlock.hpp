#pragma once
#include <iostream>
#include <map>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "Polymorph.hpp"
#include "SpellBook.hpp"

class Warlock {
    private:
        std::string name;
        std::string title;
        SpellBook spellbook;
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