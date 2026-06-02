#include "Option02.h"

namespace FRE {

double CallPayoff(double z, double K) {
    return (z > K) ? (z - K) : 0.0;
}

double PutPayoff(double z, double K) {
    return (z < K) ? (K - z) : 0.0;
}

double DigitCallPayoff(double z, double K) {
    return (z > K) ? 1.0 : 0.0;
}

double DigitPutPayoff(double z, double K) {
    return (z < K) ? 1.0 : 0.0;
}

} 
