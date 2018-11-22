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
    static RandomNumGenerator& getInstance();
    RandomNumGenerator(const RandomNumGenerator&) = delete;
    void operator=(const RandomNumGenerator&) = delete;
    int getIntegerInRange(int, int);
    double getRealInRange(double, double);

private:
    RandomNumGenerator();
    random_device rd;
    mt19937 generator;
};

#endif //GENETICALGORITHM_RANDOMNUMGENERATOR_HPP
