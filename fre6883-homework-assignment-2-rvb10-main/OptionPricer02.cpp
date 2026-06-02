#include <iostream>
#include <vector>
#include <cmath>
#include "Option02.h"
#include <iomanip> 
using namespace std;
double BinomialPrice(double s0, double u, double d, double r, int n, double k, bool isCall) {
    vector<double> prices(n + 1);
    vector<double> optionValues(n + 1);
    for (int i = 0; i <= n; i++) {
        prices[i] = s0 * pow(u, n - i) * pow(d, i);
        optionValues[i] = isCall ? FRE::CallPayoff(prices[i], k) : FRE::PutPayoff(prices[i], k);
    }
    double p = (r - d) / (u - d);
    double q = 1 - p;
    double discount = 1 / r;
    for (int j = n - 1; j >= 0; j--) {
        for (int i = 0; i <= j; i++) {
            optionValues[i] = discount * (p * optionValues[i] + q * optionValues[i + 1]);
        }
    } 
    return optionValues[0];
}
double BinomialCoeff(int n, int k) {
    double res = 1;
    for (int i = 0; i < k; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
int main() {
    double s0, u, d, r, k;
    int n;
    
    cout << "Enter s0: ";
    cin >> s0;
    cout << "Enter u: ";
    cin >> u;
    cout << "Enter d: ";
    cin >> d;
    cout << "Enter r: ";
    cin >> r;
    if (!(d < r && r < u)) {
        cout << "There is arbitrage." << endl;
        return 1;
    } else {
        cout << "There is no arbitrage" << endl;
    }
    cout << "\nEnter call option data: " << endl;
    cout << "Enter steps to expiry n: ";
    cin >> n;
    cout << "Enter strike price k: ";
    cin >> k;
    double europeanCallPrice = BinomialPrice(s0, u, d, r, n, k, true);
    double europeanPutPrice = BinomialPrice(s0, u, d, r, n, k, false);
    double digitCallPrice = 0.0, digitPutPrice = 0.0;
    double p = (r - d) / (u - d);
    double q = 1 - p;
    double discountFactor = 1 / pow(r, n);
    for (int i = 0; i <= n; i++) {
        double finalPrice = s0 * pow(u, n - i) * pow(d, i);
        double probability = BinomialCoeff(n, i) * pow(p, n - i) * pow(q, i);
        digitCallPrice += FRE::DigitCallPayoff(finalPrice, k) * probability;
        digitPutPrice += FRE::DigitPutPayoff(finalPrice, k) * probability;
    }
    digitCallPrice *= discountFactor;
    digitPutPrice *= discountFactor;
    cout << "European Call option price = " << fixed<<setprecision(2)<< europeanCallPrice << endl;
    cout << "European Put option price = " << fixed<<setprecision(2) << europeanPutPrice << endl;
    cout << "Digit Call option price = " << fixed<<setprecision(2)<< digitCallPrice <<endl;
    cout << "Digit Put option price = " << fixed<<setprecision(2)<< digitPutPrice << endl;
    return 0;
}

/* 
Enter s0: 106
Enter u: 1.15125
Enter d: 0.86862
Enter r: 1.00545
There is no arbitrage

Enter call option data: 
Enter steps to expiry n: 8
Enter strike price k: 100
European Call option price = 21.68
European Put option price = 11.43
Digit Call option price = 0.58
Digit Put option price = 0.38
*/