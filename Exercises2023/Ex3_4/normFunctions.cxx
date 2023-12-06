#include <cmath>
#include "normFunctions.h"

double NormFunction::invxsquared(double x, double mu, double sigma) {
    double K = sigma*sqrt( 2*M_PI );
    double N = pow( (x-mu)/sigma, 2 )/2;

    return exp(-N)/K;
};
