//
// Created by danny on 2018-11-08.
//
#include "City.hpp"

City::City() {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distrInt(min, max);
    x = distrInt(generator);
    y = distrInt(generator);
    name = gen_random();
}


City::City(string name, int x, int y)
    :name(std::move(name)), x(x), y(y) {}


string City::gen_random() {
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

ostream &operator<<(ostream &os, const City &c) {
    return os << c.name << ", " << c.x << ", " << c.y << endl;
}

double City::get_distance_between_cities(const City& city1) {
    int distX = abs(getX() - city1.getX());
    int distY = abs(getY() - city1.getY());
    return sqrt(pow(distX, 2) + pow(distY, 2));
}

const string &City::getName() const { return name; }

int City::getX() const { return x; }

int City::getY() const { return y; }

bool City::operator==(const City &c) const {
    return (name == c.name) && (x == c.x) && (y == c.y);
}

