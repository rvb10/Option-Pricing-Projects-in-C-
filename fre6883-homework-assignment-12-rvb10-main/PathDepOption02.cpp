#include "PathDepOption02.h"
#include <cmath>
#include <vector>

namespace fre {

double PathDepOption::PriceByMC(MCModel& Model, long N)
{
    double H = 0.0;
    SamplePath S(m);

    for (long i = 0; i < N; ++i)
    {
        Model.GenerateSamplePath(T, m, S);
        H = (i * H + Payoff(S)) / (i + 1.0);
    }
    Price = std::exp(-Model.GetR() * T) * H;
    return Price;
}

double ArthmAsianCall::Payoff(const SamplePath& S) const
{
    double Ave = 0.0;
    int d = (int)S[0].size();
    Vector one(d);
    for (int i = 0; i < d; ++i)
        one[i] = 1.0;

    for (int k = 0; k < m; ++k)
        Ave = (k * Ave + (one ^ S[k])) / (k + 1.0);

    return (Ave > K) ? (Ave - K) : 0.0;
}


std::vector<double> PathDepOption::DeltaByMC(
    MCModel& Model,
    long N,
    double eps
) const {
    Vector S0 = Model.GetS0();
    int d = (int)S0.size();
    std::vector<double> delta(d, 0.0);
    SamplePath S_orig(m), S_bumped(m);
    double r = Model.GetR();
    for (long n = 0; n < N; ++n) {
        std::vector<Vector> normals(m, Vector(d));
        for (int k = 0; k < m; ++k)
            normals[k] = Gauss(d);
        {
            Vector St = S0;
            for (int k = 0; k < m; ++k) {
                Vector drift     = (T/m) * (r + (-0.5) * Model.GetSigma() * Model.GetSigma());
                Vector diffusion = std::sqrt(T/m) * (Model.GetC() * normals[k]);
                S_orig[k] = St * exp(drift + diffusion);
                St = S_orig[k];
            }
        }
        double H0 = Payoff(S_orig);
        for (int i = 0; i < d; ++i) {
            Vector S0p = S0;
            S0p[i] *= (1.0 + eps);
            Vector St = S0p;

            for (int k = 0; k < m; ++k) {
                Vector drift     = (T/m) * (r + (-0.5) * Model.GetSigma() * Model.GetSigma());
                Vector diffusion = std::sqrt(T/m) * (Model.GetC() * normals[k]);
                S_bumped[k] = St * exp(drift + diffusion);
                St = S_bumped[k];
            }
            double H1 = Payoff(S_bumped);
            delta[i] += (H1 - H0) / (eps * S0[i]);
        }
    }
    double disc = std::exp(-r * T);
    for (int i = 0; i < d; ++i)
        delta[i] = disc * delta[i] / N;

    return delta;
}

} 
