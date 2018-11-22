//
// Created by danny on 2018-11-08.
//
#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <iostream>
#include <utility>
#include <random>
#include "RandomNumGenerator.hpp"
using namespace std;

class City {
private:
    constexpr static auto MAP_BOUNDARY = 1000;
    constexpr static auto MIN = 0;
    string name;
    int x;
    int y;

public:
    City();
    string genRandom();
    double getDistanceBetweenCities(const City&);
    inline int getX() const;
    inline int getY() const;
    bool operator == (const City&) const;
    friend ostream &operator << (ostream&, const City&);
};

#endif //GENETICALGORITHM_CITY_HPP
