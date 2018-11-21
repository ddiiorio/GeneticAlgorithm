//
// Created by danny on 2018-11-19.
//

#ifndef GENETICALGORITHM_RANDOMNUMGENERATOR_HPP
#define GENETICALGORITHM_RANDOMNUMGENERATOR_HPP
#include <iostream>
#include <string>
#include <random>

using namespace std;

class RandomNumGenerator {
public:
    RandomNumGenerator();
    int getIntegerInRange(int, int);
    double getRealInRange(double, double);
    random_device rd;
    mt19937 generator;
};

#endif //GENETICALGORITHM_RANDOMNUMGENERATOR_HPP
