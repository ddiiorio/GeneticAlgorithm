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
}

/**
 * Constructor creating a population of a specified size
 * @param size number of tours in population
 */
Population::Population(int size) {
    for (int i = 0; i < size; ++i) {
        Tour newTour;
        newTour.shuffleCities();
        tours.push_back(newTour);
    }
}

/**
 * Getter for a tour at specified index
 * @param index
 * @return tour
 */
const Tour & Population::getTour(int index) const {
    return tours.at(static_cast<unsigned long>(index));
}

/**
 * Insert a tour into specified index in a population
 * @param index position to insert tour
 * @param t new tour being inserted
 */
void Population::insertTour(int index, const Tour &t) {
    tours.at(static_cast<unsigned long>(index)) = t;
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
inline int Population::getBaseDistance() {
    return baseDistance;
}

vector<Tour> &Population::getTours() {
    return tours;
}

const int Population::getSize() {
    return POPULATION_SIZE;
}




