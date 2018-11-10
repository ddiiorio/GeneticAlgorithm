//
// Created by danny on 2018-11-09.
//

#include "RandomGenerator.hpp"

template<typename T> T
RandomGenerator::getIntegerInRange(T min, T max) {
    uniform_int_distribution<T> distribution(min, max);
    return distribution(_rng);
}


template<typename T> T
RandomGenerator::getRealInRange(T min, T max) {
    uniform_real_distribution<T> distribution(min, max);
    return distribution(_rng);
}
