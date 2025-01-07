#include "ASpell.hpp"

ASpell::ASpell(std::string const &name, std::string const &effect) : name(name), effect(effect) {
}

ASpell::~ASpell() {
}

std::string const &ASpell::getName() const {
    return name;
}

std::string const &ASpell::getEffects() const {
    return effect;
}

void ASpell::launch(const ATarget &atarget) const {
    atarget.getHitBySpell(*this);
}

ASpell::ASpell() {
}

ASpell::ASpell(const ASpell &other) {
    *this = other;
}

ASpell &ASpell::operator=(const ASpell &other) {
    name = other.name;
    effect = other.effect;
    return *this;
}
