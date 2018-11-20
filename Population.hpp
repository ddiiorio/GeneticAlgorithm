//
// Created by danny on 2018-11-09.
//
#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP

#include "Tour.hpp"

class Population {
private:
    constexpr static int POPULATION_SIZE = 32;
    vector<Tour> tours;
    int baseDistance;

public:
    Population();
    const vector<Tour> &getTours() const;
    inline Tour getTour(int);
    Tour getFittestTour();
    inline int getBaseDistance() const;
};


#endif //GENETICALGORITHM_POPULATION_HPP
