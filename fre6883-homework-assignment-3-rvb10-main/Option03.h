#pragma once
#include "BinomialTreeModel.h"  

namespace fre {
    int GetInputData(int& N, double& K);
    double *PriceByCRR(const BinomialTreeModel &Model, int N, double K, double (*Payoff)(double z, double K));
    double CallPayoff(double z, double K);
    double PutPayoff(double z, double K);
}
