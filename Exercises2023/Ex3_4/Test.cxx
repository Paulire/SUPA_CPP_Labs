// Paul M Ireland
// Test.cxx

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>

#include "FiniteFunctions.h"
#include "childFunctions.h"

int main( int argc, char * argv[] )
{
    // Check for arguments
    if ( argc != 2 ) {
        std::printf("Expected 1 input argument expected one of ['default','norm','CL','NCB']\n");
        exit(-1);
    }

    // Vars for opening the file
    std::string input_f_name = "Outputs/data/MysteryData21100.txt";
    std::vector<double> data;
    std::string cache;

    // Read data from mystery file
    std::ifstream f;
    f.open( input_f_name );

    // Load data and push to a vector
    while( !f.eof() ) {
         f >> cache;
        if( !f.eof() ) 
             data.push_back( std::stod( cache) );
    }
   
    f.close();

    // User can select function via comand line args and is processed here
    if( !strcmp( argv[1], "default" ) ) { 
        // Default 1/(1+x)
        FiniteFunction finite( -5, 5, "Outputs/data/MysteryData2110.txt" );
        finite.plotData( data, 100 );   // Plot data
        finite.plotFunction();
        finite.sample_metro( 10000 );

    } else if( !strcmp( argv[1], "norm" ) ) {
        // Guasian
        NormFunction norm( -5, 5, "Outputs/data/MysteryData21100.txt",
                           -1,  // Mean
                           1.6 ); // std
        norm.plotData( data, 100, true );
        norm.plotFunction();
        norm.sample_metro( 10000 );

    } else if( !strcmp( argv[1], "CL" ) ) {
        // Cauchy-Lorenz
        CauchyLorenzFunction cauch( -5, 5, "Outputs/data/MysteryData21100.txt",
                                    -1,  // Mean
                                    1.5 ); // std
        cauch.plotData( data, 100 );
        cauch.plotFunction();
        cauch.sample_metro( 10000 );
    } else if( !strcmp( argv[1], "NCB" ) ) {
        // Negitive Crystal Ball
        NegCrystalBallFunction ncbf( -5, 5, "Outputs/data/MysteryData21100.txt",
                                     3, // alpha 
                                     4, // n
                                     -1, // x_0 ,
                                     1.6 ); // std
        ncbf.plotData( data, 100 );
        ncbf.plotFunction( );
        ncbf.sample_metro( 10000 );
    } else {
        // No knowen args
        std::printf("Expected input argument of either ['default','norm','CL','NCB']\n" );
        exit(-1);
    }

    return 0;
}