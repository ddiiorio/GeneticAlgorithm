//
// Created by danny on 2018-11-08.
//
#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <iostream>
#include <utility>
#include <random>
using namespace std;

class city {
protected:
    string name;
    int x;
    int y;
    constexpr static auto max = 1000;
    constexpr static auto min = 0;

public:
    city();
    city(string, int, int);
    string gen_random();
    friend ostream &operator << (ostream &os, const city & c);
};


#endif //GENETICALGORITHM_CITY_HPP
