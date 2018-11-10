//
// Created by danny on 2018-11-08.
//
#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <vector>
#include <algorithm>
#include <math.h>
#include "City.hpp"

class Tour {
private:
    constexpr static int CITIES_IN_TOUR = 32;
    constexpr static int SHUFFLES = 64;
    vector<City> cities;
    double fitness;
    int distance;

public:
    Tour();
    ~Tour() = default;
    inline City & getCity(int);
    void setCity(int, City&);
    void shuffleCities();
    int getTourDistance();
    double determineFitness();
    bool containsCity(City);
    inline const vector<City> &getTour() const;
    friend ostream &operator << (ostream&, const Tour&);
};

#endif //GENETICALGORITHM_TOUR_HPP
