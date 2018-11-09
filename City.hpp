//
// Created by danny on 2018-11-08.
//
#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <iostream>
#include <utility>
#include <random>
using namespace std;

class City {
private:
    string name;
    int x;
    int y;
    constexpr static auto MAP_BOUNDARY = 1000;
    constexpr static auto MIN = 0;

public:
    City();
    City(string, int, int);
    string genRandom();
    double getDistanceBetweenCities(const City &city1);
    const string &getName() const;
    int getX() const;
    int getY() const;
    bool operator == (const City& c) const;
    friend ostream &operator << (ostream &os, const City &c);
};

#endif //GENETICALGORITHM_CITY_HPP
