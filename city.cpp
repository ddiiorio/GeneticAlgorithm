#include <utility>

//
// Created by danny on 2018-11-08.
//

#include "city.hpp"

city::city(string name, int x, int y)
    :name(std::move(name)), x(x), y(y) {}
