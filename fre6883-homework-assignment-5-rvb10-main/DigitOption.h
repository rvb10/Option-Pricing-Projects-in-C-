#pragma once
#include "Option05.h"

namespace fre {
    class DigitOption : public EurOption {
    private:
        double K1; 
        double K2; 
    public:
        DigitOption(int N_, double K1_, double K2_);
        virtual ~DigitOption(); 
        double Payoff(double z) const override;
    };
}
