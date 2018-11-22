//
// Created by danny on 2018-11-08.
//
#include "City.hpp"

/**
 * Default constructor that generates random values for x, y, and name
 */
City::City() {
    x = RandomNumGenerator::getInstance().getIntegerInRange(MIN, MAP_BOUNDARY);
    y = RandomNumGenerator::getInstance().getIntegerInRange(MIN, MAP_BOUNDARY);
    name = genRandom();
}

/**
 * Generates a random string for the city's name
 * @return string of 8 characters
 */
string City::genRandom() {
    string rName;
    int len = 8;
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    int stringLength = sizeof(alphanum) - 1;
    for (int i = 0; i < len; ++i) {
        rName += alphanum[rand() % stringLength];
    }
    return rName;
}

/**
 * Overloaded insertion operator
 * @param os output
 * @param c city being printed
 * @return output to console
 */
ostream &operator<<(ostream &os, const City &c) {
    return os << c.name << ", <" << c.x << ", " << c.y << ">" << endl;
}

/**
 * Calculates the distance between two cities
 * @param city1 city being compared to
 * @return distance between cities
 */
double City::getDistanceBetweenCities(const City &city1) {
    int distX = abs(getX() - city1.getX());
    int distY = abs(getY() - city1.getY());
    return sqrt(pow(distX, 2) + pow(distY, 2));
}

/**
 * Getter for x value
 * @return x value
 */
inline int City::getX() const { return x; }

/**
 * Getter for y value
 * @return y value
 */
inline int City::getY() const { return y; }

/**
 * Overloaded equals operator
 * @param c city being compared
 * @return boolean true if cities are equal
 */
bool City::operator==(const City &c) const {
    return (name == c.name) && (x == c.x) && (y == c.y);
}