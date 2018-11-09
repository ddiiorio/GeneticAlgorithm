//
// Created by danny on 2018-11-08.
//
#include "City.hpp"

/**
 * Default constructor that generates random values for x, y, and name
 */
City::City() {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distrInt(min, max);
    x = distrInt(generator);
    y = distrInt(generator);
    name = genRandom();
}

/**
 * 3-parameter constructor
 * @param name
 * @param x
 * @param y
 */
City::City(string name, int x, int y)
    :name(std::move(name)), x(x), y(y) {}

/**
 * Generates a random string for the city's name
 * @return
 */
string City::genRandom() {
    char *s;
    int len = 8;
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    s[len] = 0;
    return s;
}

/**
 * Overloaded insertion operator
 * @param os
 * @param c
 * @return output
 */
ostream &operator<<(ostream &os, const City &c) {
    return os << c.name << ", " << c.x << ", " << c.y << endl;
}

/**
 * Calculates the distance between two cities
 * @param city1
 * @return distance
 */
double City::getDistanceBetweenCities(const City &city1) {
    int distX = abs(getX() - city1.getX());
    int distY = abs(getY() - city1.getY());
    return sqrt(pow(distX, 2) + pow(distY, 2));
}

/**
 * Getter for city name
 * @return name
 */
const string &City::getName() const { return name; }

/**
 * Getter for x value
 * @return x
 */
int City::getX() const { return x; }

/**
 * Getter for y value
 * @return y
 */
int City::getY() const { return y; }

/**
 * Overloaded equals operator
 * @param c
 * @return boolean
 */
bool City::operator==(const City &c) const {
    return (name == c.name) && (x == c.x) && (y == c.y);
}

