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
    constexpr static int NUMBER_OF_PARENTS = 2;
    constexpr static int PARENT_POOL_SIZE = 5;
    RandomGenerator random;

public:
    GeneticAlgorithm() = default;
    Population evolve(Population&);
    void selection(Population&) const;
    Tour crossover(Tour&, Tour&);
    void mutate(Tour &t) const;
    Tour crossoverSelection(Population&) const;
};

#endif //GENETICALGORITHM_GENETICALGORITHM_HPP
