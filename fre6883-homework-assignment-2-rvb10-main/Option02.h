#pragma once
#ifndef OPTION02_H
#define OPTION02_H

namespace FRE {
    double CallPayoff(double z, double K);
    double PutPayoff(double z, double K);
    double DigitCallPayoff(double z, double K);
    double DigitPutPayoff(double z, double K);
}

#endif 
