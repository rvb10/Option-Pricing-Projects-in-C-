#include "Spread.h"

namespace fre {
    double StrangleOpt::Payoff(double z) const {
        if (z <= K1) return K1 - z;
        else if (K2 < z) return z - K2;
        return 0.0;
    }

    double ButterflyOpt::Payoff(double z) const {
        double mid = (K1 + K2) / 2.0;
        if (z <= K1 || z >= K2) return 0.0;
        if (z <= mid) return z - K1;
        return K2 - z;
    }
}
