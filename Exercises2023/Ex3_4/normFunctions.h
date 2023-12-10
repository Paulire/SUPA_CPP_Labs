#include "FiniteFunctions.h"

class NormFunction : public FiniteFunction {
public:
    using FiniteFunction::FiniteFunction;
    std::vector< std::pair<double,double> > scanFunction(int Nscan = 1000); //Scan over function to plot it (slight hack needed to plot function in gnuplot)
    double callFunction(double x, double mu, double sigma);

private:
    double guassian( double x, double mu, double sigma ); //The default functional form
};