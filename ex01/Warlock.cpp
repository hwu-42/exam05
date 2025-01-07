#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title) {
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
    for (std::map<std::string, ASpell*>::iterator it = spells.begin(); it != spells.end(); it++) {
        delete it->second;
    }
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
        if (spells.find(aspell->getName()) == spells.end()) {
            spells[aspell->getName()] = aspell;
        }
    }
}

void Warlock::forgetSpell(std::string const &name) {
    if (spells.find(name) != spells.end()) {
        delete spells[name];
        spells.erase(name);
    }
}

void Warlock::launchSpell(std::string const &name, ATarget &atarget) {
    if (spells.find(name) != spells.end()) {
        spells[name]->launch(atarget);
    }
}