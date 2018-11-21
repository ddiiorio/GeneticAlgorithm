#include "Population.hpp"
#include "GeneticAlgorithm.hpp"

int main() {
    GeneticAlgorithm zz{};
    Population aa;

    cout << aa.getFittestTour().determineFitness() << endl;

    for (int i = 0; i < GeneticAlgorithm::getIterations(); ++i) {
        aa = zz.evolve(aa);
    }
    cout << aa.getFittestTour().determineFitness() << endl;

    return 0;
}