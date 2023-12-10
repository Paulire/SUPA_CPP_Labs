#include "FiniteFunctions.h"

class NormFunction : public FiniteFunction {
public:
    using FiniteFunction::FiniteFunction;
    double callFunction(double x );

private:
    double guassian( double x ); //The default functional form

    // Additional functions and verlibles added
    double mean;
    double var;
    double getMean( void );
    void getVar( double w );
};