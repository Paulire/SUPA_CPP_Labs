#include <cmath>
#include <vector>
#include "normFunctions.h"

double NormFunction::invxsquared(double x, double mu, double sigma) {
    double K = sigma*sqrt( 2*M_PI );
    double N = pow( (x-mu)/sigma, 2 )/2;

    return exp(-N)/K;
};

std::vector< std::pair<double,double> > NormFunction::scanFunction(int Nscan = 1000) {
    std::vector< std::pair<double,double> > function_scan;

    std::vector<double,double> points;

    // Get mean
    double mean = 0;
    double var = 0;

    for( int i=0; i<points.size(); i++ ) {
        // Mean of x weighted by y
        mean += points[i,0]*points[i,1];
    }

    // Get std
    return function_scan;
}