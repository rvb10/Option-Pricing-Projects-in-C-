#include "Option01.h"
#include "BinomialTreeModel.h"
#include <iostream>
#include <cmath>
using namespace std;

namespace fre {
    double PriceByCRR1(double S0, double U, double D, double R, unsigned int N, double K)
    {
        double q = RiskNeutProb(U, D, R);
        double Price[N + 1];

        for (unsigned int i = 0; i <= N; i++)
            Price[i] = 0.0;

        for (unsigned int i = 0; i <= N; i++)
        {
            Price[i] = CallPayoff(CalculateAssetPrice(S0, U, D, N, i), K);
        }

        for (int n = N - 1; n >= 0; n--)
        {
            for (int i = 0; i <= n; i++)
            {
                Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / R;
            }
        }
        return Price[0];
    }

    double CallPayoff(double z, double K)
    {
        return (z > K) ? (z - K) : 0.0; 
    }

    double doubleFactorial(int n) {
        if (n == 0 || n == 1) return 1;

        double dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = i * dp[i - 2];  
        }

        return dp[n];  
    }

    double Factorial(int n) {
        if (n == 0 || n == 1) return 1;

        double dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = i * dp[i - 1];  
        }

        return dp[n];
    }

    double BinomialCoefficient(int N, int i) {
        return Factorial(N) / (Factorial(i) * Factorial(N - i));
    }

    double PriceByCRR2(double S0, double U, double D, double R, unsigned int N, double K)
    {
        double q = RiskNeutProb(U, D, R);
        double price = 0.0;

        for (unsigned int i = 0; i <= N; i++)
        {
            double S_N_i = CalculateAssetPrice(S0, U, D, N, i);
            double payoff = CallPayoff(S_N_i, K);
            double prob = BinomialCoefficient(N, i) * pow(q, i) * pow(1 - q, N - i);
            price += prob * payoff;
        }

        return price / pow(R, N);
    }
}
