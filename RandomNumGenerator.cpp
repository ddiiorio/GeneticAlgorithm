//
// Created by danny on 2018-11-20.
//
#include "RandomNumGenerator.hpp"

RandomNumGenerator::RandomNumGenerator() {
    mt19937 generator(rd());
}

int RandomNumGenerator::getIntegerInRange(int minInclusive, int maxInclusive) {
    uniform_int_distribution<int> distribution(minInclusive, maxInclusive);
    return distribution(generator);
}

double RandomNumGenerator::getRealInRange(double minInclusive, double maxInclusive) {
    uniform_real_distribution<double> distribution(minInclusive, maxInclusive);
    return distribution(generator);
}


