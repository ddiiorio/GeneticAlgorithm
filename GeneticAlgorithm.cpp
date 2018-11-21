//
// Created by danny on 2018-11-09.
//

#include "GeneticAlgorithm.hpp"

Population GeneticAlgorithm::evolve(Population & p) {
    Population newPop;
    //selection(newPop);
    Tour fit = p.getFittestTour();
    cout << fit.determineFitness() << endl;
    vector<Tour> newPopTours;
    newPopTours.push_back(fit);
    vector<Tour> parents = crossoverSelection(p);
    for (int j = NUMBER_OF_ELITES; j < Population::getSize(); ++j) {
        Tour child = crossover(parents.at(0), parents.at(1));
        newPopTours.push_back(child);
    }
    for (int i = NUMBER_OF_ELITES; i < Population::getSize(); i++) {
        mutate(newPopTours.at(i));
    }
    newPop.setTours(newPopTours);

    return newPop;
}


void GeneticAlgorithm::selection(Population& p) const {
    Tour fittest = p.getFittestTour();
    for (auto it = p.getTours().begin(); it != p.getTours().end(); ++it) {
        if (*it == fittest) {
            std::rotate(p.getTours().begin(), it, p.getTours().end());
            break;
        }
    }
}

Tour GeneticAlgorithm::crossover(Tour t1, Tour t2) {
    Tour child(true);
    vector<City> parent1 = t1.getTour();
    vector<City> parent2 = t2.getTour();

    // Get random cutoff number
    auto endPos = random.getIntegerInRange(0, (int) parent1.size()-1);

    // Loop and add the sub tour from parent1 to our child
    for (int i = 0; i <= endPos; ++i) {
        child.getTour().push_back(t1.getCity(i));
    }

    int newCount = 0;
    // Loop through parent2's tour and add city if it doesn't already exist
    while (child.getTour().size() < 32) {
        if (!child.containsCity(t2.getCity(newCount))) {
            child.getTour().push_back(t2.getCity(newCount));
        }
        newCount++;
    }

    return child;
}


void GeneticAlgorithm::mutate(Tour &t) {
    for (int tourPosition1 = 0; tourPosition1 < t.getTour().size(); ++tourPosition1){
        auto randDbl = random.getRealInRange(0, 1);
        if (randDbl < MUTATION_RATE) {
            auto tourPosition2 = random.getIntegerInRange
                    (0, CITIES_IN_TOUR-1);
            // get cities
            City city1 = t.getCity(tourPosition1);
            City city2 = t.getCity(tourPosition2);

            // swap
            t.setCity(tourPosition1, city2);
            t.setCity(tourPosition2, city1);
        }
    }
}

/**
 * Creates a subset of tours from the population and returns the fittest of
 * this subset
 * @param p Population for selection
 * @return fittest tour from the population subset
 */
vector<Tour> GeneticAlgorithm::crossoverSelection(Population& p) {
    selection(p);
    vector<Tour> popCopy = p.getTours();
    popCopy.erase(popCopy.begin());
    popCopy.shrink_to_fit();
    vector<Tour> pool1;
    for (int i = 0; i < PARENT_POOL_SIZE; ++i) {
        random_shuffle(popCopy.begin(), popCopy.end());
        auto randomNum = random.getIntegerInRange
                (0, (int) p.getTours().size()-1);
        pool1.push_back(p.getTour(randomNum));
        popCopy.erase(popCopy.begin());
        popCopy.shrink_to_fit();
    }
    vector<Tour> pool2;
    for (int i = 0; i < PARENT_POOL_SIZE; ++i) {
        random_shuffle(popCopy.begin(), popCopy.end());
        auto randomNum = random.getIntegerInRange
                (0, (int) p.getTours().size()-1);
        pool2.push_back(p.getTour(randomNum));
        popCopy.erase(popCopy.begin());
        popCopy.shrink_to_fit();
    }
    sort(pool1.begin(), pool1.end());
    sort(pool2.begin(), pool2.end());
    vector<Tour> parents;
    parents.push_back(pool1.at(0));
    parents.push_back(pool2.at(0));
    return parents;
}




