#include "TargetGenerator.hpp"

void TargetGenerator::learnTargetType(ATarget *target) {
    for (std::vector<ATarget *>::iterator it = targets.begin(); it != targets.end(); it++) {
        if ((*it)->getType() == target->getType()) {
            return;
        }
    }
    targets.push_back(target->clone());
}

void TargetGenerator::forgetTargetType(std::string const &type) {
    for (std::vector<ATarget *>::iterator it = targets.begin(); it != targets.end(); it++) {
        if ((*it)->getType() == type) {
            delete *it;
            targets.erase(it);
            return;
        }
    }
}

ATarget *TargetGenerator::createTarget(std::string const &type) {
    for (std::vector<ATarget *>::iterator it = targets.begin(); it != targets.end(); it++) {
        if ((*it)->getType() == type) {
            return (*it)->clone();
        }
    }
    return NULL;
}

TargetGenerator::TargetGenerator(const TargetGenerator &other) {
    *this = other;
}

TargetGenerator &TargetGenerator::operator=(const TargetGenerator &other) {
    for (std::vector<ATarget *>::iterator it = targets.begin(); it != targets.end(); it++) {
        delete *it;
    }
    targets.clear();
    for (std::vector<ATarget *>::const_iterator it = other.targets.begin(); it != other.targets.end(); it++) {
        targets.push_back((*it)->clone());
    }
    return *this;
}


TargetGenerator::TargetGenerator() {
}

TargetGenerator::~TargetGenerator() {
    for (std::vector<ATarget *>::iterator it = targets.begin(); it != targets.end(); it++) {
        delete *it;
    }
}