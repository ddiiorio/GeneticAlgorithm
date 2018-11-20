//
// Created by danny on 2018-11-08.
//
#include "Tour.hpp"

/**
 * Default constructor, initializes fitness and distance to 0
 */
Tour::Tour() : fitness{0}, distance{0} {
    for (int i = 0; i < CITIES_IN_TOUR; ++i) {
        cities.emplace_back();
    }
}

/**
 * Gets the city at given index in the tour
 * @param pos
 * @return City
 */
inline City & Tour::getCity(int pos) {
    return cities.at(pos);
}

/**
 * Inserts a city at a specified position in a tour
 * @param position
 * @param city
 */
void Tour::setCity(int position, City& city) {
    cities.at(position) = city;
    fitness = 0;
    distance = 0;
}

/**
 * Simple insert for a city into tour
 * @param city
 */
void Tour::insertCity(City& city) {
    cities.push_back(city);
}

/**
 * Shuffles cities in the tour
 */
void Tour::shuffleCities() {
    for (int i = 0; i < SHUFFLES; ++i) {
        auto rng = default_random_engine {};
        shuffle(cities.begin(), cities.end(), rng);
    }
}

/**
 * Calculates entire distance contained in the tour
 * @return distance
 */
int Tour::getTourDistance() {
    if (distance == 0) {
        int tourDistance = 0;
        for (int cityIndex = 0; cityIndex < cities.size(); cityIndex++) {
            City originCity = getCity(cityIndex);
            City toCity;
            // Check we're not on our Tour's last City, if we are set our
            // Tour's final destination City to our starting City
            if (cityIndex + 1 < cities.size()) {
                toCity = getCity(cityIndex + 1);
            }
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
 * Calculates fitness value of the tour
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
 * @param city1
 * @return boolean
 */
bool Tour::containsCity(City city1) {
    auto it = find(cities.begin(), cities.end(), city1);
    return it != cities.end();
}

/**
 * Getter for tour vector
 * @return cities
 */
inline const vector<City> &Tour::getTour() const {
    return cities;
}

/**
 * Overloaded insertion operator
 * @param os
 * @param t
 * @return output
 */
ostream &operator<<(ostream &os, const Tour &t) {
    for (const City &c : t.getTour()) {
        os << c;
    }
    return os;
}

bool Tour::operator==(const Tour &t) const {
    return (cities == t.getTour());
}