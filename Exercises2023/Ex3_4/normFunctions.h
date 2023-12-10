#include "FiniteFunctions.h"

class NormFunction : public FiniteFunction {
public:
    NormFunction();
    NormFunction(double range_min, double range_max, std::string outfile);
    double callFunction(double x );

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