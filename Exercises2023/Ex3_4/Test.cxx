#include <iostream>
#include <vector>
#include <string>

#include <cstdlib>

#include "FiniteFunctions.h"
#include "normFunctions.h"

int main( int argc, char * argv[] )
{
    std::string input_f_name = "Outputs/data/MysteryData12141.txt";
    std::vector<double> data;
    std::string cache;

    // Read data from mystery file
    std::ifstream f;
    f.open( input_f_name );

    while( !f.eof() ) {
         f >> cache;
        if( !f.eof() ) 
             data.push_back( std::stod( cache) );
    }
   
    f.close();


    /*FiniteFunction finite( -5, 5, "Outputs/data/MysteryData12141.txt" );
    finite.plotData( data, 100 );
    finite.plotFunction();*/

    NormFunction norm( -5, 5, "Outputs/data/MysteryData21100.txt");
    norm.plotData( data, 100 );
    norm.plotFunction();

    /*CauchyLorenzFunction cauch( -5, 5, "Outputs/data/MysteryData21100.txt" );
    cauch.plotData( data, 100 );
    cauch.plotFunction();*/

    /*NegCrystalBallFunction ncbf( -5, 5, "Outputs/data/MysteryData21100.txt" );
    ncbf.plotData( data, 100 );
    ncbf.plotFunction( );*/
    

    return 0;
}