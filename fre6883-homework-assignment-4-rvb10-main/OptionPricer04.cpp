#include "BinomialTreeModel.h"
#include "Option04.h"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace fre;

int main()
{
    int N;
    double U, D, R, S0, K, K1, K2;
    cout << "Enter number of steps (N): ";
    cin >> N;
    cout << "Enter up factor (U): ";
    cin >> U;
    cout << "Enter down factor (D): ";
    cin >> D;
    cout << "Enter risk-free rate per step (R): ";
    cin >> R;
    cout << "Enter initial stock price (S0): ";
    cin >> S0;
    cout << "Enter strike price (K): ";
    cin >> K;
    cout << "Enter lower strike for spread (K1): ";
    cin >> K1;
    cout << "Enter upper strike for spread (K2): ";
    cin >> K2;

    BinomialTreeModel Model(S0, U, D, R);

    Call call(N, K);
    OptionCalculation callCalculation(&call);
    cout << "European call option price = "
        << fixed << setprecision(2) << callCalculation.PriceByCRR(Model) << endl;
    Put put(N, K);
    OptionCalculation putCalculation(&put);
    cout << "European put option price = "
        << fixed << setprecision(2) << putCalculation.PriceByCRR(Model) << endl;
    BullSpread bullSpread(N, K1, K2);
    OptionCalculation bullSpreadCalculation(&bullSpread);
    cout << "European bull spread option price = "
        << fixed << setprecision(2) << bullSpreadCalculation.PriceByCRR(Model) << endl;
    BearSpread bearSpread(N, K1, K2);
    OptionCalculation bearSpreadCalculation(&bearSpread);
    cout << "European bear spread option price = "
        << fixed << setprecision(2) << bearSpreadCalculation.PriceByCRR(Model) << endl;

    return 0;
}

/*
Enter number of steps (N): 
8
Enter up factor (U): 1.15125
Enter down factor (D): 0.86862
Enter risk-free rate per step (R): 1.00545
Enter initial stock price (S0): 106
Enter strike price (K): 100
Enter lower strike for spread (K1): 100
Enter upper strike for spread (K2): 110
European call option price = 21.68
European put option price = 11.43
European bull spread option price = 4.72
European bear spread option price = 4.86
*/