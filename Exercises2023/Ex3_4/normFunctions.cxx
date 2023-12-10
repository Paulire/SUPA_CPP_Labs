#include <cmath>
#include <vector>
#include <iostream>
#include "normFunctions.h"

double NormFunction::guassian(double x) {
    double K = var*sqrt( 2*M_PI );
    double N = pow( (x-mean)/var, 2 )/2;

    return exp(-N)/K;
};

double NormFunction::getMean( void ) {
    double weight = 0;

    // Calulated the weighted mean of of the function
    for( auto pt : m_data ) {
        mean += pt.first*pt.second;
        weight += pt.second;
    }
    
    mean /= weight;

    return weight;
};

void NormFunction::getVar( double weight ) {
    // Calulated the weighted variance of of the function
    for( auto pt : m_data ) {
        var += pow( pt.first - mean, 2 )*pt.second;
        weight += pt.second;
    }
    
    var /= weight;
};

double NormFunction::callFunction(double x ) {
    if( !mean ) {
        double w = this->getMean( );
        this->getVar( w );
    }

    return this->guassian(x);
};

