//
// Created by danny on 2018-11-09.
//
#ifndef GENETICALGORITHM_GENETICALGORITHM_HPP
#define GENETICALGORITHM_GENETICALGORITHM_HPP

#include "Population.hpp"
#include "RandomNumGenerator.hpp"
#include <algorithm>

class GeneticAlgorithm {
private:
    constexpr static double MUTATION_RATE = 0.15;
    constexpr static int CITIES_IN_TOUR = 32;
    constexpr static int NUMBER_OF_PARENTS = 2;
    constexpr static int PARENT_POOL_SIZE = 5;
    constexpr static int NUMBER_OF_ELITES = 1;
    constexpr static int ITERATIONS = 200;
    RandomNumGenerator random;

public:
    GeneticAlgorithm() = default;
    static int getIterations();
    Population evolve(Population&);
    void selection(Population&) const;
    Tour crossover(Tour, Tour);
    void mutate(Tour &t) ;
    vector<Tour> selectParents(Population &);
};

#endif //GENETICALGORITHM_GENETICALGORITHM_HPP
