//
// Created by danny on 2018-11-09.
//

#include "GeneticAlgorithm.hpp"

Tour GeneticAlgorithm::crossover(Tour& t1, Tour& t2) {
    Tour child;
    const vector<City> &childCities = child.getTour();
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

    // Loop through parent2's city tour
    for (int i = 0; i < parent2.size(); i++) {
        // If child doesn't have the city add it
        if (!child.containsCity(t2.getCity(i))) {
            // Loop to find a spare position in the child's tour
            for (int ii = 0; ii < childCities.size(); ii++) {
                // Spare position found, add city
                if (child.getCity(ii) == null) {
                    child.setCity(ii, t2.getCity(i));
                    break;
                }
            }
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
