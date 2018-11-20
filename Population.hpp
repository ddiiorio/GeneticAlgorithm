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
    explicit Population(int);
    vector<Tour> &getTours();
    const Tour & getTour(int) const;
    void insertTour(int, const Tour &);
    Tour getFittestTour();
    inline int getBaseDistance();
};


#endif //GENETICALGORITHM_POPULATION_HPP
