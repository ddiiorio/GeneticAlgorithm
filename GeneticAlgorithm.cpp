//
// Created by danny on 2018-11-09.
//

#include "GeneticAlgorithm.hpp"

Population GeneticAlgorithm::evolve(Population & p) {
    Population newPop;
    selection(newPop);
    for (int i = NUMBER_OF_ELITES; i < Population::getSize(); i++) {
        vector<Tour> parents = crossoverSelection(p);
        Tour child = crossover(parents.at(0), parents.at(1));
        //newPop.insertTour(i, child);
    }

    for (int i = NUMBER_OF_ELITES; i < Population::getSize(); i++) {
        mutate(newPop.getTour(i));
    }

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

Tour GeneticAlgorithm::crossover(Tour& t1, Tour& t2) {
    Tour child(true);
    vector<City> parent1 = t1.getTour();
    vector<City> parent2 = t2.getTour();

    // Get random start and end sub tour positions for parent1's tour
    auto startPos = random.getIntegerInRange(0, (int) parent1.size());
    auto endPos = random.getIntegerInRange(0, (int) parent1.size());

    // Loop and add the sub tour from parent1 to our child
    for (int i = 0; i < parent1.size(); ++i) {
        // If our start position is less than the end position
        if (startPos < endPos && i > startPos && i < endPos) {
            //cout << "t1 city : " << i << t1.getCity(i);
            child.getTour().push_back(t1.getCity(i));
        } // If our start position is larger
        else if (startPos > endPos) {
            if (!(i < startPos && i > endPos)) {
                child.getTour().push_back(t1.getCity(i));
            }
        }
    }
    cout << child.getTour().size() << endl;
    // Loop through parent2's tour and add city if it doesn't already exist
    for (int i = 0; i < parent2.size(); i++) {
        if (!child.containsCity(t2.getCity(i))) {
            //cout << "t2 city : " << i << t2.getCity(i);
            child.getTour().push_back(t2.getCity(i));
        }
    }
    cout << child.getTour().size() << endl;
    return child;
}


void GeneticAlgorithm::mutate(Tour &t) {
    for (int tourPosition1 = 0; tourPosition1 < t.getTour().size(); ++tourPosition1){
        auto randDbl = random.getRealInRange(0, 1);
        if (randDbl < MUTATION_RATE) {
            auto tourPosition2 = random.getIntegerInRange
                    (0, CITIES_IN_TOUR);
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
                (0, (int) p.getTours().size());
        pool1.push_back(p.getTour(randomNum));
        popCopy.erase(popCopy.begin());
        popCopy.shrink_to_fit();
    }
    vector<Tour> pool2;
    for (int i = 0; i < PARENT_POOL_SIZE; ++i) {
        random_shuffle(popCopy.begin(), popCopy.end());
        auto randomNum = random.getIntegerInRange
                (0, (int) p.getTours().size());
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




