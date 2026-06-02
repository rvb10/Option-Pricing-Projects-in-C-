#include "BinomialTreeModel.h"
#include "BinLattice02.h"
#include "Option08.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
using namespace fre;

void PrintLatticeToFile(ofstream& fout, const BinLattice<double>& L)
{
    int N = L.GetN();
    for (int n = 0; n <= N; ++n)
    {
        for (int i = 0; i <= n; ++i)
        {
            fout << setw(10) << fixed << setprecision(3) << L.GetNode(n, i);
        }
        fout << endl;
    }
    fout << endl;
}

int main()
{
    BinomialTreeModel Model;
    if (Model.GetInputData() != 0) return 1;

    int N;
    double K;
    cout << "Enter steps to expiry N: "; cin >> N;
    cout << "Enter strike price K: "; cin >> K;

    ofstream fout("result.txt");
    if (!fout)
    {
        cerr << "Cannot open result.txt for writing." << endl;
        return 1;
    }

    // ----- CALL OPTION -----
    Call call(N, K);
    OptionCalculation calcCall(&call);
    BinLattice<double> Xcall, Ycall;
    double callPrice = calcCall.PriceByCRR(Model, Xcall, Ycall);

    cout << "\nEuropean call prices by PriceByCRR: " << fixed << setprecision(3) << callPrice << endl;
    fout << "European call prices by PriceByCRR: " << fixed << setprecision(3) << callPrice << endl;
    fout << "European call prices by HW6 PriceByCRR: " << fixed << setprecision(3) << callPrice << endl;

    fout << "\nStock positions in replicating strategy:\n";
    PrintLatticeToFile(fout, Xcall);

    fout << "\nMoney market account positions in replicating strategy:\n";
    PrintLatticeToFile(fout, Ycall);

    // ----- PUT OPTION -----
    Put put(N, K);
    OptionCalculation calcPut(&put);
    BinLattice<double> Xput, Yput;
    double putPrice = calcPut.PriceByCRR(Model, Xput, Yput);

    cout << "European put prices by PriceByCRR: " << fixed << setprecision(3) << putPrice << endl;
    fout << "European put prices by PriceByCRR: " << fixed << setprecision(3) << putPrice << endl;
    fout << "European put prices by HW6 PriceByCRR: " << fixed << setprecision(3) << putPrice << endl;

    fout << "\nStock positions in replicating strategy:\n";
    PrintLatticeToFile(fout, Xput);

    fout << "\nMoney market account positions in replicating strategy:\n";
    PrintLatticeToFile(fout, Yput);

    fout.close();
    cout << "\nResults written to result.txt" << endl;

    return 0;
}
