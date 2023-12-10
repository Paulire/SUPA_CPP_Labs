#include <cmath>
#include <vector>
#include <iostream>
#include "normFunctions.h"

double NormFunction::guassian(double x, double mu, double sigma) {
    double K = sigma*sqrt( 2*M_PI );
    double N = pow( (x-mu)/sigma, 2 )/2;

    return exp(-N)/K;
};

double NormFunction::callFunction(double x, double mu, double sigma) {return this->guassian(x,mu,sigma);};

std::vector< std::pair<double,double> > NormFunction::scanFunction(int Nscan) {
    std::vector< std::pair<double,double> > function_scan;

    // Get mean
    double mean = 0;
    double total_weight = 0;
    double var = 0;
    double step = (m_RMax - m_RMin)/(double)Nscan;
    double x = m_RMin;

    // Mean of x weighted by y
    for( auto pr: m_data ) {
        mean += pr.first*pr.second;
        total_weight += pr.second;
    }

    mean /= total_weight;

    // Mean of x weighted by y
    for( auto pr: m_data ) {
        var += pow(pr.first-mean,2)*pr.second;
    }

    var /= total_weight;

    std::cout << "Mean=" << mean << std::endl;
    std::cout << "Variance=" << var << std::endl;

    //For each scan point push back the x and y values 
    for (int i = 0; i < Nscan; i++){
        function_scan.push_back( std::make_pair(x,this->callFunction(x,mean,var)));
        x += step;
    }

    // Get std
    return function_scan;
}