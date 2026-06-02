#include <iostream>
#include <vector>
#include "PathDepOption02.h"

using namespace std;
using namespace fre;

int main() {
    int d = 3;
    Vector S0(d);
    S0[0] = 40.0;
    S0[1] = 60.0;
    S0[2] = 100.0;

    double r = 0.03;  
    Matrix C(d, Vector(d));
    C[0][0] =  0.1;  C[0][1] = -0.1;  C[0][2] =  0.0;
    C[1][0] = -0.1;  C[1][1] =  0.2;  C[1][2] =  0.0;
    C[2][0] =  0.0;  C[2][1] =  0.0;  C[2][2] =  0.3;

    MCModel Model(S0, r, C);

    double T = 1.0 / 12.0;  
    double K = 200.0;        
    int m = 30;              

    ArthmAsianCall Option(T, K, m);

    long N = 3000;           
    double eps = 0.001;     

    double price = Option.PriceByMC(Model, N);
    cout << "Arithmetic Basket Call Price = " << price << endl;

    vector<double> deltas = Option.DeltaByMC(Model, N, eps);
    for (int i = 0; i < (int)deltas.size(); ++i) {
        cout << "delta[" << i << "] = " << deltas[i] << endl;
    }

    return 0;
}
/*
[ec2-user@ip-172-31-1-73 fre6883-homework-assignment-12-rvb10]$ ./HW12
Arithmetic Basket Call Price = 2.24047
delta[0] = 0.507911
delta[1] = 0.515274
delta[2] = 0.532821
*/