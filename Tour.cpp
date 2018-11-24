//
// Created by danny on 2018-11-08.
//
#include "Tour.hpp"

/**
 * Default constructor, initializes fitness and distance to 0, and fills
 * vector of cities if it is not constructed as a child.
 * If it is constructed as a child, it is initialized with an empty vector
 * @param child boolean determining if tour is a child or not
 */
Tour::Tour(bool child) : fitness{0}, distance{0} {
    if (!child) {
        for (int i = 0; i < CITIES_IN_TOUR; ++i) {
            cities.emplace_back();
        }
        determineFitness();
        getTourDistance();
    }
}

/**
 * Gets the city at given index in the tour
 * @param position index position
 * @return City at index
 */
inline City & Tour::getCity(int position) {
    return cities.at(static_cast<unsigned long>(position));
}

/**
 * Shuffles cities in the tour 'SHUFFLES' number of times
 */
void Tour::shuffleCities() {
    for (int i = 0; i < SHUFFLES; ++i) {
        swapCities();
    }
}

/**
 * Swaps two cities in a tour from random indexes
 */
void Tour::swapCities() {
    auto tourPosition1 = RandomNumGenerator::getInstance().
            getIntegerInRange(0, CITIES_IN_TOUR - 1);
    auto tourPosition2 = RandomNumGenerator::getInstance().
            getIntegerInRange(0, CITIES_IN_TOUR - 1);
    swap(cities.at((unsigned long) tourPosition1), cities.at((unsigned long) tourPosition2));
}

/**
 * Calculates entire distance of the tour based on city order
 * @return total tour distance
 */
int Tour::getTourDistance() {
    if (distance == 0) {
        int tourDistance = 0;
        for (unsigned long cityIndex = 0; cityIndex < cities.size(); cityIndex++) {
            City originCity = getCity((int) cityIndex);
            City toCity;
            // Check we're not on our tour's last city
            if (cityIndex + 1 < cities.size()) {
                toCity = getCity((int) cityIndex + 1);
            }
            // if we are on our tour's final destination city, set it to our starting city
            // so we get the distance between the first and last city
            else {
                toCity = getCity(0);
            }
            // Get the distance between the two cities
            tourDistance += (int) originCity.getDistanceBetweenCities(toCity);
        }
        distance = tourDistance;
    }
    return distance;
}

/**
 * Calculates fitness of the tour, multiplied by a scalar (1 million)
 * for a more readable value
 * @return fitness value
 */
double Tour::determineFitness() {
    if (fitness == 0) {
        fitness = (1/(double) getTourDistance()) * 1000000;
    }
    return fitness;
}

/**
 * Checks if a tour contains a given city
 * @param city1 city being searched for
 * @return boolean true if tour contains city
 */
bool Tour::containsCity(City city1) {
    auto it = find(cities.begin(), cities.end(), city1);
    return it != cities.end();
}

/**
 * Getter for tour vector
 * @return cities vector
 */
vector<City> &Tour::getTour() {
    return cities;
}

/**
 * Overloaded insertion operator
 * @param os output stream
 * @param t tour being output
 * @return output to console
 */
ostream &operator<<(ostream &os, Tour &t) {
    for (City &c : t.getTour()) {
        os << c;
    }
    return os;
}

/**
 * Overloaded equals operator to determine if tours are equal
 * @param t tour being compared
 * @return true if tours are equal
 */
bool Tour::operator==(Tour &t) {
    return (fitness == t.fitness);
}

/**
 * Overloaded comparison operator used in sorting tours
 * @param t tour being compared
 * @return true or false
 */
bool Tour::operator<(const Tour &t) const {
    return fitness > t.fitness;
}