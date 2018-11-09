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
    vector<City> tour;
    double fitness;
    int distance;
    constexpr static int CITIES_IN_TOUR = 32;

public:
    Tour();
    ~Tour() = default;
    City getCity(int);
    void shuffleCities();
    int getTourDistance();
    double determineFitness();
    bool containsCity(City);

};



#endif //GENETICALGORITHM_TOUR_HPP
