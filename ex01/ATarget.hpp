#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {
    protected:
        std::string type;

    public:
        
        ATarget(std::string const &type);
        virtual ~ATarget();
        std::string const &getType() const;
        virtual ATarget *clone() const = 0;
        virtual void getHitBySpell(const ASpell &spell) const;
    private:
        ATarget();
        ATarget(const ATarget &other);
        ATarget &operator=(const ATarget &other);

};