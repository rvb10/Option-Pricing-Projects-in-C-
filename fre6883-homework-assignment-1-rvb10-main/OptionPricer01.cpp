// OptionPricer01.cpp
//

#include "BinomialTreeModel.h"
#include "Option01.h"
#include <iostream>
#include <iomanip>
using namespace std;
using namespace fre;

/*int main()
{
    double u = 1.15125, d = 0.86862, r = 1.00545;
    double s0 = 106.00;
    double k = 100.00;
    const unsigned int N = 8;

    double optionPrice = PriceByCRR(s0, u, d, r, N, k);
    cout << "European call option price = " << fixed << setprecision(2) << optionPrice << endl;
    
    return 0;
}
/*
European call option price = 21.68
*/

int main()
{
    double s0, u, d, r;
    unsigned int n;
    double k;

    cout << "Enter s0: ";
    cin >> s0;
    cout << "Enter u: ";
    cin >> u;
    cout << "Enter d: ";
    cin >> d;
    cout << "Enter r: ";
    cin >> r;
    cout << "Enter Number of Steps n: ";
    cin >> n;
    cout << "Enter Strike Price k: ";
    cin >> k;

    cout << fixed << setprecision(6);
    cout << "\nS0 = " << s0 << endl;
    cout << "u = " << u << "   d = " << d << "   r = " << r << endl;
    cout << "N = " << n << endl;

    double optionPrice1 = PriceByCRR1(s0, u, d, r, n, k);

    double optionPrice2 = PriceByCRR2(s0, u, d, r, n, k);

    cout << "\nEuropean call option price = " << optionPrice2 << endl;
    cout << "\nCalculate European call option price by HW1 Function: " << optionPrice1 << endl;
    cout << "\nCalculate European call option price by HW1 Function V2: " << optionPrice2 << endl;

    return 0;
}

/* 

OUTPUT : -
[ec2-user@ip-172-31-91-128 fre6883-homework-assignment-1-rvb10]$ ./OptionPricer01
Enter s0: 106
Enter u: 1.151250
Enter d: 0.868620
Enter r: 1.0054500
Enter Number of Steps n: 8
Enter Strike Price k: 100

S0 = 106.000000
u = 1.151250   d = 0.868620   r = 1.005450
N = 8

European call option price = 21.681102

Calculate European call option price by HW1 Function: 21.681102

Calculate European call option price by HW1 Function V2: 21.681102

*/