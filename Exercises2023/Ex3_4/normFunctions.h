#include "FiniteFunctions.h"

class NormFunction : FiniteFunction {
public:
    std::vector< std::pair<double,double> > scanFunction(int Nscan = 1000); //Scan over function to plot it (slight hack needed to plot function in gnuplot)

private:
    double invxsquared( double x, double mu, double sigma ); //The default functional form
};