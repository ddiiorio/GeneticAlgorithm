//
// Created by danny on 2018-11-09.
//
#include "Population.hpp"

/**
 * Default constructor that fills tours vector with shuffled tours
 */
Population::Population() {
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        Tour newTour;
        newTour.shuffleCities();
        tours.push_back(newTour);
    }
    baseDistance = getFittestTour().getTourDistance();
    //make_heap(tours.begin(), tours.end());
}

/**
 * Getter for a tour at specified index
 * @param index
 * @return tour
 */
inline Tour Population::getTour(int index) {
    return tours.at(index);
}

/**
 * Iterates through vector of tours and returns the one with best fitness rating
 * @return tour
 */
Tour Population::getFittestTour() {
    Tour fittest = tours.at(0);
    for (auto it = tours.begin() + 1; it < tours.end(); ++it) {
        if (fittest.determineFitness() <= it->determineFitness()) {
            fittest = *it;
        }
    }
    return fittest;
}

/**
 * Getter for base distance
 * @return base distance
 */
inline int Population::getBaseDistance() const {
    return baseDistance;
}

const vector<Tour> &Population::getTours() const {
    return tours;
}
