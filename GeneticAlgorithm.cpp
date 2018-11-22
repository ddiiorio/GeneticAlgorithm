//
// Created by danny on 2018-11-09.
//

#include <chrono>
#include "GeneticAlgorithm.hpp"

/**
 * Evolves a population by moving the fittest tour to the front, adding
 * child tours to the rest of the population, and then mutating them
 * @param p population being genetically evolved
 * @return
 */
void GeneticAlgorithm::evolve(Population & p) {
    Population newPop;
    Tour fit = p.getFittestTour();
    vector<Tour> newPopTours;
    newPopTours.push_back(fit);
    vector<Tour> parents = selectParents(p);
    for (int j = NUMBER_OF_ELITES; j < Population::getSize(); ++j) {
        Tour child = crossover(parents.at(0), parents.at(1));
        newPopTours.push_back(child);
    }
    for (int i = NUMBER_OF_ELITES; i < Population::getSize(); i++) {
        mutate(newPopTours.at((unsigned long) i));
    }
    newPop.setTours(newPopTours);
    p = newPop;
}

/**
 * Finds the fittest tour in a population and moves it to the front
 * of the tour list
 * @param p population to find fittest tour in
 */
void GeneticAlgorithm::selection(Population& p) const {
    Tour fittest = p.getFittestTour();
    for (auto it = p.getTours().begin(); it != p.getTours().end(); ++it) {
        if (*it == fittest) {
            std::rotate(p.getTours().begin(), it, p.getTours().end());
            break;
        }
    }
}

/**
 * Takes two parent tours and creates a child tour by filling it with
 * a random number of cities from parent 1, and filling the rest of the
 * tour with cities from parent 2
 * @param t1 parent tour 1
 * @param t2 parent tour 2
 * @return child tour
 */
Tour GeneticAlgorithm::crossover(Tour t1, Tour t2) {
    Tour child(true);
    vector<City> parent1 = t1.getTour();
    vector<City> parent2 = t2.getTour();
    // Get random cutoff number
    auto endPos = RandomNumGenerator::getInstance().
            getIntegerInRange(0, (int) parent1.size() - 1);

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

/**
 * Takes a tour and "mutates" it by randomly selecting two cities at
 * a time and swaps their positions in the tour
 * @param t tour being mutated
 */
void GeneticAlgorithm::mutate(Tour &t) {
    for (unsigned long tourPosition1 = 0; tourPosition1 < t.getTour().size();
        ++tourPosition1){
        auto randDbl = RandomNumGenerator::getInstance()
                .getRealInRange(0, 1);
        if (randDbl < MUTATION_RATE) {
            auto tourPosition2 = RandomNumGenerator::getInstance()
                    .getIntegerInRange(0, CITIES_IN_TOUR - 1);
            // swap
            swap(t.getTour().at(tourPosition1),
                    t.getTour().at((unsigned long) tourPosition2));
        }
    }
}

/**
 * Creates subsets of tours from the population and returns the fittest of
 * each subset
 * @param p Population for selection
 * @return vector of fittest tours from the population subset
 */
vector<Tour> GeneticAlgorithm::selectParents(Population &p) {
    selection(p);
    vector<Tour> popCopy = p.getTours();
    popCopy.erase(popCopy.begin());
    popCopy.shrink_to_fit();
    vector<Tour> parents;
    for (int i = 0; i < NUMBER_OF_PARENTS; ++i) {
        vector<Tour> pool;
        for (int j = 0; j < PARENT_POOL_SIZE; ++j) {
            long seed = chrono::system_clock::now().time_since_epoch().count();
            shuffle(popCopy.begin(), popCopy.end(), default_random_engine(seed));
            auto randomNum = RandomNumGenerator::getInstance()
                    .getIntegerInRange(0, (int) p.getTours().size() - 1);
            pool.push_back(p.getTour(randomNum));
            popCopy.erase(popCopy.begin());
            popCopy.shrink_to_fit();
        }
        sort(pool.begin(), pool.end());
        parents.push_back(pool.at(0));
        pool.clear();
    }
    return parents;
}

/**
 * Evolves a population using the genetic algorithm for a minimum number of iterations
 * specified by ITERATIONS static variable, and stops after it surpasses that number when
 * the improvement factor is less than a specified number
 * @param p population being evolved by algorithm
 */
void GeneticAlgorithm::optimize(Population &p) {
    cout << "Population's starting statistics : \nFitness level: " <<
        p.getFittestTour().determineFitness() << "\nFittest tour's total distance: " <<
        p.getFittestTour().getTourDistance() << endl;
    cout << "============================================" << endl;
    cout << "Evolving... please wait..." << endl;
    int baseDistance = p.getBaseDistance();
    double improvementFactor{0.0};
    int cycles{0};

    while (cycles < ITERATIONS || improvementFactor > IMPROVEMENT) {
        evolve(p);
        improvementFactor = (double) p.getFittestTour().getTourDistance()
                            / (double) baseDistance;
        if (cycles % 100 == 0 && cycles != 0) {
            cout << "Fitness level after " << cycles << " evolutions: "
                 << p.getFittestTour().determineFitness() << "\nImprovement factor: "
                 << setprecision(4) << improvementFactor << "\n..." << endl;
        }
        cycles++;
    }

    cout << "============================================" << endl;
    cout << "Population's statistics after " << ITERATIONS << " evolutions: "
         << "\nFitness level: " << p.getFittestTour().determineFitness() <<
         "\nFittest tour's total distance: " <<
         p.getFittestTour().getTourDistance() << endl;
}