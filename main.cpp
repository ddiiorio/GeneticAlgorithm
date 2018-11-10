#include "City.hpp"
#include "Tour.hpp"
#include "Population.hpp"

int main() {
    Tour zz;
    Population aa;
//    for (City t : zz.getTour()) {
//        cout << t;
//    }
//
    cout << zz.getTourDistance() << endl;
    cout << aa.getFittestTour().determineFitness();

    return 0;
}