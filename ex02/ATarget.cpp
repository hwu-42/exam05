#include "ATarget.hpp"

ATarget::ATarget(std::string const &type) : type(type) {
}

ATarget::~ATarget() {
}

std::string const &ATarget::getType() const {
    return type;
}

void ATarget::getHitBySpell(const ASpell &spell) const {
    std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}

ATarget::ATarget() {
}

ATarget::ATarget(const ATarget &other) {
    *this = other;
}

ATarget &ATarget::operator=(const ATarget &other) {
    type = other.type;
    return *this;
}