// Paul M Ireland
// childFunctions.h

#include "FiniteFunctions.h"

/*
* Class declerations for normal distrobution
*/
class NormFunction : public FiniteFunction {
public:
    NormFunction();
    NormFunction(double range_min, double range_max, std::string outfile, double x_0, double sigma );
    double callFunction(double x );

    // Some addition verlibles for functions
    double fun_mean; // Mean of Guassian
    double fun_std;  // Standard deviation

private:
    double guassian( double x ); //The default functional form

    // Additional functions and verlibles added
};

/*
* Class definitions for negitive crystal ball distrobution
*/
class CauchyLorenzFunction : public FiniteFunction {
public:
    CauchyLorenzFunction();
    CauchyLorenzFunction(double range_min, double range_max, std::string outfile, double x_0, double gamma );
    double callFunction( double x );
    
    // Some addition verlibles for functions
    double fun_mean;  
    double fun_fwhm;

private:
    double CauchyLorenz( double x ); //The default functional form
};

/*
* Class definition for negitive crystal ball distrobution
*/
class NegCrystalBallFunction : public FiniteFunction {
public:
    NegCrystalBallFunction();
    NegCrystalBallFunction(double range_min, double range_max, std::string outfile, double alpha, double n, double x_0, double sigma );
    double callFunction(double x );
    void setNCBparams( void );

    // Negitive crystal ball paramiters
    double fun_alpha = 1.0;
    double fun_n = 2.00;
    double fun_std = 2;
    double fun_mean = 0;
    double A, B, C, D, N;

private:
    double NegCrystalBall( double x );
    double guassian( double x );
    double poly( double x );
};