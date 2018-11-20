//
// Created by danny on 2018-11-09.
//
#ifndef GENETICALGORITHM_GENETICALGORITHM_HPP
#define GENETICALGORITHM_GENETICALGORITHM_HPP

#include "Population.hpp"
#include "RandomGenerator.hpp"
#include <algorithm>

class GeneticAlgorithm {
private:
    constexpr static double MUTATION_RATE = 0.15;
    constexpr static int CITIES_IN_TOUR = 32;
    RandomGenerator random;

public:
    GeneticAlgorithm() = default;
    void selection(Population&) const;
    Tour crossover(Tour&, Tour&);
    void mutate(Tour &t) const;
};

#endif //GENETICALGORITHM_GENETICALGORITHM_HPP
