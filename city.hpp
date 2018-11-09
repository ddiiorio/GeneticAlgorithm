//
// Created by danny on 2018-11-08.
//
#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP
#include <iostream>
using namespace std;

constexpr int max = 1000;
constexpr int min = 0;

class city {
protected:
    string name;
    int x;
    int y;

public:
    city() = default;
    city(string, int, int);
};


#endif //GENETICALGORITHM_CITY_HPP
