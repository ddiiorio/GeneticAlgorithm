//
// Created by danny on 2018-11-08.
//
#include "city.hpp"

city::city() {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distrInt(min, max);
    x = distrInt(generator);
    y = distrInt(generator);
    name = gen_random();
}


city::city(string name, int x, int y)
    :name(std::move(name)), x(x), y(y) {}


string city::gen_random() {
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

ostream &operator<<(ostream &os, const city &c) {
    return os << c.name << ", " << c.x << ", " << c.y << endl;
}
