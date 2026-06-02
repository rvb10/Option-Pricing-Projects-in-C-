#include "DigitOption.h"

namespace fre {

DigitOption::DigitOption(int N_, double K1_, double K2_) 
    : EurOption(N_), K1(K1_), K2(K2_) {}

DigitOption::~DigitOption() {}
double DigitOption::Payoff(double z) const {
    if (this->K1 < z && z < this->K2)
        return 1.0;
    return 0.0;
}

} 
