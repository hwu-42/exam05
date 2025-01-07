#include "SpellBook.hpp"

SpellBook::SpellBook() {
}

SpellBook::~SpellBook() {
    for (std::vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++) {
        delete *it;
    }
}

void SpellBook::learnSpell(ASpell *spell) {
    for (std::vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++) {
        if ((*it)->getName() == spell->getName()) {
            return;
        }
    }
    spells.push_back(spell->clone());
}

void SpellBook::forgetSpell(std::string const &spellName) {
    for (std::vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++) {
        if ((*it)->getName() == spellName) {
            delete *it;
            spells.erase(it);
            return;
        }
    }
}

ASpell *SpellBook::createSpell(std::string const &spellName) {
    for (std::vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++) {
        if ((*it)->getName() == spellName) {
            return (*it)->clone();
        }
    }
    return NULL;
}

SpellBook::SpellBook(const SpellBook &other) {
    *this = other;
}

SpellBook &SpellBook::operator=(const SpellBook &other) {
    for (std::vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++) {
        delete *it;
    }
    spells.clear();
    for (std::vector<ASpell *>::const_iterator it = other.spells.begin(); it != other.spells.end(); it++) {
        spells.push_back((*it)->clone());
    }
    return *this;
}