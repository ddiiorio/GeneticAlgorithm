//
// Created by danny on 2018-11-08.
//
#include "Tour.hpp"

Tour::Tour() : fitness{0}, distance{0} {}

City Tour::getCity(int pos) {
    return tour.at(pos);
}

void Tour::shuffle_cities() {
    auto rng = default_random_engine {};
    shuffle(tour.begin(), tour.end(), rng);
}

int Tour::get_tour_distance() {
    if (distance == 0) {
        int tourDistance = 0;
        // Loop through our Tour's cities
        for (int cityIndex = 0; cityIndex < tour.size(); cityIndex++) {
            // Get City we're travelling from
            City fromCity = getCity(cityIndex);
            // City we're travelling to
            City destinationCity;
            // Check we're not on our Tour's last City, if we are set our
            // Tour's final destination City to our starting City
            if(cityIndex + 1 < tour.size()){
                destinationCity = getCity(cityIndex + 1);
            }
            else{
                destinationCity = getCity(0);
            }
            // Get the distance between the two cities
            tourDistance += fromCity.get_distance_between_cities(destinationCity);
        }
        distance = tourDistance;
    }
    return distance;
}

double Tour::determine_fitness() {
    if (fitness == 0) {
        fitness = 1/(double) get_tour_distance();
    }
    return fitness;
}


bool Tour::contains_city(const City city1) {
    auto it = find(tour.begin(), tour.end(), city1);
    return it != tour.end();
}

