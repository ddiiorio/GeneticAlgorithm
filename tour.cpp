//
// Created by danny on 2018-11-08.
//
#include "tour.hpp"

tour::tour() {}

void tour::shuffle_cities() {
    auto rng = default_random_engine {};
    shuffle(cities.begin(), cities.end(), rng);
}

unsigned int tour::get_distance_between_cities() {
    return 0;
}

unsigned int tour::get_tour_distance() {
    return 0;
}

unsigned int tour::determine_fitness() {
    return 0;
}

bool tour::contains_city(city city1) {
    auto it = find (cities.begin(), cities.end(), city1);
    if (it != cities.end())
        return true;
    else
        return false;
}

