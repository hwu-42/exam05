#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell {
    protected:
        std::string name;
        std::string effect;

    public:
        ASpell(std::string const &name, std::string const &effect);
        virtual ~ASpell();
        std::string const &getName() const;
        std::string const &getEffects() const;
        virtual ASpell *clone() const = 0;
        virtual void launch(const ATarget &atarget) const;
    private:
        ASpell();
        ASpell(const ASpell &other);
        ASpell &operator=(const ASpell &other);
};