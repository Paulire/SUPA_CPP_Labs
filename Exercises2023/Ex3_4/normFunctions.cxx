#include <cmath>
#include <vector>
#include <iostream>
#include "normFunctions.h"

/*
* For normal distrobution 
*/
// Empty constructer
NormFunction::NormFunction( ) {
    FiniteFunction( );
};

// Initlized constructer
NormFunction::NormFunction(double range_min, double range_max, std::string outfile) {
    FiniteFunction(range_min, range_max, outfile);
};

double NormFunction::guassian(double x) {
    double stdiv = sqrt( var );
    double C = stdiv*sqrt( 2*M_PI );
    double N = pow( (x-mean)/stdiv, 2 )/2;

    return exp(-N)/C;
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

/*
* For Cauchy-Lorenz Distrobution
*/
// Empty constructer
CauchyLorenzFunction::CauchyLorenzFunction( ) {
    NormFunction( );
};

// Initlized constructer
CauchyLorenzFunction::CauchyLorenzFunction(double range_min, double range_max, std::string outfile) {
    NormFunction(range_min, range_max, outfile);
};

double CauchyLorenzFunction::CauchyLorenz( double x) {
    return 1/( 
        M_PI*var*( 1+pow( (x-mean)/var, 2 ))
    );
};

void CauchyLorenzFunction::getFWHM( void ) {
    double stdiv = sqrt( var );
    fwhm = 2*sqrt( 2*log(2) )*stdiv;
};

double CauchyLorenzFunction::callFunction( double x ) {
    if( !fwhm ) {
        double w = this->getMean( );
        this->getVar( w );
        this->getFWHM( );
    }

    return this->CauchyLorenz(x);
};

/*
* Negitive Crystal Ball function
*/
NegCrystalBallFunction::NegCrystalBallFunction( ) {
    NormFunction( );
};

// Initlized constructer
NegCrystalBallFunction::NegCrystalBallFunction(double range_min, double range_max, std::string outfile) {
    NormFunction(range_min, range_max, outfile);
};

void NegCrystalBallFunction::setNCBparams( void ) {
    A = pow(n/alpha,n)*exp( -pow(alpha,2)/2);
    B = n/alpha - alpha;
    C = (n/alpha)*(1/(n-1))*exp( -pow(alpha,2)/2);
    D = sqrt(M_PI/2)*( 1 - erf( alpha/sqrt(2)));
    N = 1/(var*(C+D));

    std::cout << "A: " << A << "\nB: " << B << "\nC: " << C << "\nD: " << D << "\nN: " << N << std::endl;
};

double NegCrystalBallFunction::guassian(double x) {
    double K = pow( (x-mean)/var, 2 )/2;

    return N*exp(-K);
};

double NegCrystalBallFunction::poly( double x ) {
    return N*A*pow(B-(x-mean)/var,-n );
}

double NegCrystalBallFunction::NegCrystalBall( double x )
{
    double conditition = ( x - mean )/var;

    if( conditition > -alpha)
        return this->guassian( x );
    else if( conditition <= -alpha )
        return this->poly( x );

    std::cout << "Unknown error in Crystal ball function\n";
    exit(-1);
}

double NegCrystalBallFunction::callFunction( double x ) {
    if( !mean ) {
        double w = this->getMean( );
        this->getVar( w );
        this->setNCBparams( );
    }

    return this->NegCrystalBall(x);
};