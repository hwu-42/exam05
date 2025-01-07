#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title) {
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
    this->spellbook.~SpellBook();
    std::cout << name << ": My job here is done!" << std::endl;
}

std::string const &Warlock::getName() const {
    return name;
}

std::string const &Warlock::getTitle() const {
    return title;
}

void Warlock::setTitle(std::string const &title) {
    this->title = title;
}

void Warlock::introduce() const {
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *aspell) {
    if (aspell) {
        spellbook.learnSpell(aspell);
    }
}

void Warlock::forgetSpell(std::string const &name) {
    spellbook.forgetSpell(name);
}

void Warlock::launchSpell(std::string const &name, ATarget &atarget) {
    ASpell *spell = spellbook.createSpell(name);
    if (spell) {
        std::cout << name << ": " << spell->getName() << " is cast!" << std::endl;
        spell->launch(atarget);
        delete spell;
    }
}