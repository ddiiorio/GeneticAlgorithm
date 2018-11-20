//
// Created by danny on 2018-11-09.
//

#ifndef GENETICALGORITHM_RANDOMGENERATOR_HPP
#define GENETICALGORITHM_RANDOMGENERATOR_HPP

#include <iostream>
#include <string>
#include <random>
using std::mt19937;
using std::uniform_int_distribution;
using std::uniform_real_distribution;

class RandomGenerator {
public:
    RandomGenerator() = default;
    template<typename T> static T getIntegerInRange(T, T);
    template<typename T> static T getRealInRange(T, T);

private:
    static mt19937 _rng;
};

#endif //GENETICALGORITHM_RANDOMGENERATOR_HPP
