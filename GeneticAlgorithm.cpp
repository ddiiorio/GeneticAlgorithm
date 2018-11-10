//
// Created by danny on 2018-11-09.
//

#include "GeneticAlgorithm.hpp"

GeneticAlgorithm::GeneticAlgorithm() {}

void GeneticAlgorithm::mutate(Tour &t) const {
    for (int tourPosition1 = 0; tourPosition1 < t.getTour().size(); ++tourPosition1){
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<int> distrInt(0, CITIES_IN_TOUR);
        uniform_real_distribution<double> distrDbl(0, 1);
        double randDbl = distrDbl(generator);
        if (randDbl < MUTATION_RATE) {
            int tourPosition2 = distrInt(generator);

            // get cities
            City city1 = t.getCity(tourPosition1);
            City city2 = t.getCity(tourPosition2);

            // swap
            t.setCity(tourPosition1, city1);
            t.setCity(tourPosition2, city2);
        }
    }
}
