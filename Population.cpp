//
// Created by danny on 2018-11-09.
//
#include "Population.hpp"

/**
 * Default constructor that fills tours vector with shuffled tours
 */
Population::Population() {
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        Tour newTour(false);
        newTour.shuffleCities();
        tours.push_back(newTour);
    }
    baseDistance = getFittestTour().getTourDistance();
}

/**
 * Getter for a tour at specified index
 * @param index tour index in population
 * @return tour at index
 */
Tour & Population::getTour(int index) {
    return tours.at(static_cast<unsigned long>(index));
}

/**
 * Iterates through vector of tours and returns the one with best fitness rating
 * @return fittest tour
 */
Tour Population::getFittestTour() {
    auto fittest = tours.at(0);
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
int Population::getBaseDistance() {
    return baseDistance;
}

/**
 * Getter for populations vector of tours
 * @return tours vector
 */
vector<Tour> &Population::getTours() {
    return tours;
}

/**
 * Getter for const value for the population's size
 * @return population size
 */
int Population::getSize() {
    return POPULATION_SIZE;
}

/**
 * Setter for the populations vector of tours
 * @param tours vector of tours
 */
void Population::setTours(const vector<Tour> &tours) {
    Population::tours = tours;
}




