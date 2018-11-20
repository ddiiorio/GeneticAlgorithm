//
// Created by danny on 2018-11-19.
//

#ifndef GENETICALGORITHM_RANDOMNUMGENERATOR_HPP
#define GENETICALGORITHM_RANDOMNUMGENERATOR_HPP
#include <iostream>
#include <string>
#include <random>

using std::mt19937;
using std::uniform_int_distribution;
using std::uniform_real_distribution;

class RandomNumGenerator {
public:
    RandomNumGenerator() = default;
    template<typename T> T getIntegerInRange(T minInclusive, T maxInclusive);
    template<typename T> T getRealInRange(T minInclusive, T maxInclusive);

private:
    mt19937 _rng;
};

template<typename T> T
RandomNumGenerator::getIntegerInRange(T minInclusive, T maxInclusive) {
    uniform_int_distribution<int> distribution(minInclusive, maxInclusive);
    return distribution(_rng);
}


template<typename T> T
RandomNumGenerator::getRealInRange(T minInclusive, T maxInclusive) {
    uniform_real_distribution<T> distribution(minInclusive, maxInclusive);
    return distribution(_rng);
}

#endif //GENETICALGORITHM_RANDOMNUMGENERATOR_HPP
