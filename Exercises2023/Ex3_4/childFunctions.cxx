// Paul M Ireland
// childFunctions.cxx

#include <cmath>
#include <vector>
#include <iostream>
#include "childFunctions.h"

/*
* For normal distrobution 
*/
// Empty constructer
NormFunction::NormFunction( ) {
    fun_mean = 1;
    fun_std = 1;
    this->checkPath("normalFunction");
    FiniteFunction( );
};

// Initlized constructer
NormFunction::NormFunction(double range_min, double range_max, std::string outfile, double x_0, double sigma ) {
    fun_mean = x_0;
    fun_std = sigma;

    this->checkPath("normalFunction");

    FiniteFunction(range_min, range_max, outfile);
};

// Conputes the Guassian
double NormFunction::guassian(double x) {
    double C = fun_std*sqrt( 2*M_PI );
    double N = pow( (x-fun_mean)/fun_std, 2 )/2;
    return exp(-N)/C;
};


// Calls the Guassian
double NormFunction::callFunction(double x ) {
    return this->guassian(x);
};

/*
* For Cauchy-Lorenz Distrobution
*/
// Empty constructer
CauchyLorenzFunction::CauchyLorenzFunction( ) {
    fun_mean = 1;
    fun_fwhm = 1;
    this->checkPath("CauchyLorenzFunction");
    FiniteFunction( );
};

// Initlized constructer
CauchyLorenzFunction::CauchyLorenzFunction(double range_min, double range_max, std::string outfile, double x_0, double gamma ) {
    // Ensures conditions for inputs are met
    if ( gamma <= 0 ) {
        std::printf( "Warning, 'gamma' must be greader than zero, setting to 1 by default\n");
        fun_fwhm = 1;
    } else
        fun_fwhm = gamma;

    this->checkPath("CauchyLorenzFunction");

    fun_mean = x_0;

    FiniteFunction(range_min, range_max, outfile);
};

// Computes the Cauchy-Lorenz function
double CauchyLorenzFunction::CauchyLorenz( double x) {
    return 1/( 
        M_PI*fun_fwhm*( 1+pow( (x-fun_mean)/fun_fwhm, 2 ) )
    );
};

// Calls the Cauchy-Lorenz function
double CauchyLorenzFunction::callFunction( double x ) {
    return this->CauchyLorenz(x);
};

/*
* Negitive Crystal Ball function
*/
// Empty constructer
NegCrystalBallFunction::NegCrystalBallFunction( ) {
    this->checkPath("Negitive Crystal Ball Function");
    FiniteFunction( );
}

// Initlized constructer
NegCrystalBallFunction::NegCrystalBallFunction(double range_min, double range_max, std::string outfile, double alpha, double n, double x_0, double sigma ) {
    // Ensures conditions for inputs are met
    if( alpha <= 0 ) {
        std::printf( "Warning, 'alpha' must be greader than 0, setting to 1 by default\n");
        fun_alpha = 1;
    } else
        fun_alpha = alpha;
    if( n <= 1 ) {
        std::printf( "Warning, 'alpha' must be greader than 1, setting to 2 by default\n");
        fun_n = 2;
    } else
        fun_n = n;

    fun_std = sigma;
    fun_mean = x_0;

    this->setNCBparams();

    this->checkPath("Negitive Crystal Ball Function");
    
    FiniteFunction(range_min, range_max, outfile);
};

// Computes the Crystal ball paramiters
void NegCrystalBallFunction::setNCBparams( void ) {
    A = pow(fun_n/fun_alpha,fun_n)*exp( -pow(fun_alpha,2)/2);
    B = fun_n/fun_alpha - fun_alpha;
    C = (fun_n/fun_alpha)*(1/(fun_n-1))*exp( -pow(fun_alpha,2)/2);
    D = sqrt(M_PI/2)*( 1 - erf( fun_alpha/sqrt(2)));
    N = 1/(fun_std*(C+D));
};

// Coputes the Guassian component
double NegCrystalBallFunction::guassian(double x) {
    double K = pow( (x-fun_mean)/fun_std, 2 )/2;

    return N*exp(-K);
};

// Computes the inverse polynomial component
double NegCrystalBallFunction::poly( double x ) {
    return N*A*pow(B-(x-fun_mean)/fun_std,-fun_n );
}

// Computes the negitive crytal ball!
double NegCrystalBallFunction::NegCrystalBall( double x )
{
    double conditition = ( x - fun_mean )/fun_std;

    if( conditition > -fun_alpha)
        return this->guassian( x );
    else if( conditition <= -fun_alpha )
        return this->poly( x );

    std::cout << "Unknown error in Crystal ball function\n";
    exit(-1);
}

// Calls the negitive crystal ball function
double NegCrystalBallFunction::callFunction( double x ) {
    return this->NegCrystalBall(x);
};