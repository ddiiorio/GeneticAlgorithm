//
// Created by danny on 2018-11-08.
//
#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <vector>
#include <algorithm>
#include "city.hpp"


class tour {
protected:
    vector<city> cities;
    int fitness;

public:
    tour();
    ~tour() = default;
    void shuffle_cities();
    unsigned int get_distance_between_cities(); //calculate the as-the-crow-flies distance between two cities
    unsigned int get_tour_distance(); //reports the distance between the cities as they are listed in a tour
    unsigned int determine_fitness(); //determines the fitness of a tour
    bool contains_city(city); //checks if a tour contains a specified city

};



#endif //GENETICALGORITHM_TOUR_HPP
