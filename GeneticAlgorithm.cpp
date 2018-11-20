//
// Created by danny on 2018-11-09.
//

#include "GeneticAlgorithm.hpp"

Population GeneticAlgorithm::evolve(Population &) {







    return Population();
}


void GeneticAlgorithm::selection(Population& p) const {
    const Tour fittest = p.getFittestTour();
    for (auto it = p.getTours().begin(); it != p.getTours().end(); ++it) {
        if (*it == fittest) {
            std::rotate(p.getTours().begin(), it, p.getTours().end());
            break;
        }
    }
}

Tour GeneticAlgorithm::crossover(Tour& t1, Tour& t2) {
    Tour child;
    const vector<City> &parent1 = t1.getTour();
    const vector<City> &parent2 = t2.getTour();

    // Get start and end sub tour positions for parent1's tour
    int startPos = random.getIntegerInRange(0, (int) parent1.size());
    int endPos = random.getIntegerInRange(0, (int) parent1.size());

    // Loop and add the sub tour from parent1 to our child
    for (int i = 0; i < parent1.size(); ++i) {
        // If our start position is less than the end position
        if (startPos < endPos && i > startPos && i < endPos) {
            child.setCity(i, t1.getCity(i));
        } // If our start position is larger
        else if (startPos > endPos) {
            if (!(i < startPos && i > endPos)) {
                child.setCity(i, t1.getCity(i));
            }
        }
    }

    // Loop through parent2's tour and add city if it doesn't already exist
    for (int i = 0; i < parent2.size(); i++) {
        if (!child.containsCity(t2.getCity(i))) {
            child.insertCity(t2.getCity(i));
        }
    }
    return child;
}


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

/**
 * Creates a subset of tours from the population and returns the fittest of
 * this subset
 * @param p Population for selection
 * @return fittest tour from the population subset
 */
Tour GeneticAlgorithm::crossoverSelection(Population& p) const {
    Population pp(PARENT_POOL_SIZE);
    for (int i = 0; i < PARENT_POOL_SIZE; ++i) {
        int randomNum = RandomGenerator::getIntegerInRange(0, (int) p.getTours().size());
        pp.insertTour(randomNum, p.getTour(randomNum));
    }
    return pp.getFittestTour();
}




