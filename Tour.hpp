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
protected:
    vector<City> cities;
    double fitness;
    int distance;

public:
    Tour();
    ~Tour() = default;
    City getCity(int);
    void shuffle_cities();
    int get_tour_distance(); //reports the distance between the cities as they are listed in a Tour
    double determine_fitness(); //determines the fitness of a Tour
    bool contains_city(City); //checks if a Tour contains a specified City

};



#endif //GENETICALGORITHM_TOUR_HPP
