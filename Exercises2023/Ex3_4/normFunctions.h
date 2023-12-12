#include "FiniteFunctions.h"

class NormFunction : public FiniteFunction {
public:
    NormFunction();
    NormFunction(double range_min, double range_max, std::string outfile);
    virtual double callFunction(double x );

    // Some additions to automate calulations
    double mean;
    double var;
    double getMean( void );
    void getVar( double w );

private:
    double guassian( double x ); //The default functional form

    // Additional functions and verlibles added
};

class CauchyLorenzFunction : public NormFunction {
public:
    CauchyLorenzFunction();
    CauchyLorenzFunction(double range_min, double range_max, std::string outfile);
    double callFunction( double x );

protected:
    double fwhm;
    void getFWHM( void );

private:
    double CauchyLorenz( double x ); //The default functional form
};

class NegCrystalBallFunction : public NormFunction {
public:
    NegCrystalBallFunction();
    NegCrystalBallFunction(double range_min, double range_max, std::string outfile);
    double callFunction(double x );
    void setNCBparams( void );

    // Negitive crystal ball paramiters
    double alpha=1.5;
    double n = 1.01;
    double A, B, C, D, N;

private:
    double NegCrystalBall( double x );
    double guassian( double x );
    double poly( double x );
};