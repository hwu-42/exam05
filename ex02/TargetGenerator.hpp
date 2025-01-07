#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "ATarget.hpp"

class TargetGenerator{
public:
    TargetGenerator();
    ~TargetGenerator();
    void learnTargetType(ATarget *target);
    void forgetTargetType(std::string const &type);
    ATarget *createTarget(std::string const &type);
private:
    std::vector<ATarget *> targets;
    TargetGenerator(TargetGenerator const &other);
    TargetGenerator &operator=(TargetGenerator const &other);
};