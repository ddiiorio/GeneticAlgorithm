//
// Created by danny on 2018-11-09.
//

#include "Population.hpp"


Population::Population() {
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        Tour newTour;
        newTour.shuffleCities();
        tours.push_back(newTour);
    }
}

Tour Population::getFittestTour() {
    Tour fittest = tours.at(0);
    for (auto it = tours.begin() + 1; it < tours.end(); ++it) {
        if (fittest.determineFitness() <= it->determineFitness()) {
            fittest = *it;
        }
    }
    return fittest;
}
