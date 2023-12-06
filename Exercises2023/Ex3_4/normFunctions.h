#include "FiniteFunctions.h"

class NormFunction : FiniteFunction {
private:
    double invxsquared( double x, double mu, double sigma ); //The default functional form
};