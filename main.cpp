#include "Population.hpp"
#include "GeneticAlgorithm.hpp"

int main() {
    GeneticAlgorithm geneticAlgorithm{};
    Population population;

    geneticAlgorithm.optimize(population);

    return 0;
}