#include <iostream>
#include <iomanip>
#include "BinomialTreeModel.h"
#include "Option05.h"
#include "DigitOption.h"
#include "Spread.h"

using namespace std;
using namespace fre;

int main() {
    int N;
    double U, D, R, S0, K1, K2;

    cout << "Enter number of steps (N): ";
    cin >> N;

    cout << "Enter initial stock price (S0): ";
    cin >> S0;

    cout << "Enter up factor (U): ";
    cin >> U;

    cout << "Enter down factor (D): ";
    cin >> D;

    cout << "Enter risk-free interest rate factor (R): ";
    cin >> R;

    cout << "Enter first strike price (K1): ";
    cin >> K1;

    cout << "Enter second strike price (K2): ";
    cin >> K2;

    BinomialTreeModel Model(S0, U, D, R);

    DigitOption option1(N, K1, K2);
    OptionCalculation option1Calculation(&option1);
    cout << "European double digit option price = "
         << fixed << setprecision(2) << option1Calculation.PriceByCRR(Model) << endl;

    StrangleOpt option2(N, K1, K2);
    OptionCalculation option2Calculation(&option2);
    cout << "European strangle option price = "
         << fixed << setprecision(2) << option2Calculation.PriceByCRR(Model) << endl;

    ButterflyOpt option3(N, K1, K2);
    OptionCalculation option3Calculation(&option3);
    cout << "European butterfly option price = "
         << fixed << setprecision(2) << option3Calculation.PriceByCRR(Model) << endl;

    return 0;
}



/*
Enter number of steps (N): 8
Enter initial stock price (S0): 106
Enter up factor (U): 1.15125
Enter down factor (D): 0.86862
Enter risk-free interest rate factor (R): 1.00545
Enter first strike price (K1): 100
Enter second strike price (K2): 110


European double digit option price = 0.26
European strangle option price = 28.39
European butterfly option price = 1.04
*/ 