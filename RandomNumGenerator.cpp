//
// Created by danny on 2018-11-20.
//
#include "RandomNumGenerator.hpp"

RandomNumGenerator::RandomNumGenerator() {
    mt19937 generator(rd());
}

/**
 * Generates a random integer in the supplied range
 * @param minInclusive minimum value
 * @param maxInclusive maximum value
 * @return random integer in range
 */
int RandomNumGenerator::getIntegerInRange(int minInclusive, int maxInclusive) {
    uniform_int_distribution<int> distribution(minInclusive, maxInclusive);
    return distribution(generator);
}

/**
 * Generates a random double in the supplied range
 * @param minInclusive minimum value
 * @param maxInclusive maximum value
 * @return random double in range
 */
double RandomNumGenerator::getRealInRange(double minInclusive, double maxInclusive) {
    uniform_real_distribution<double> distribution(minInclusive, maxInclusive);
    return distribution(generator);
}


