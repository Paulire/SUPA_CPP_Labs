#include <iostream>
#include <vector>
#include <string>

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


    FiniteFunction finite( -5, 5, "Outputs/data/MysteryData12141.txt" );
    finite.plotData( data, 20 );
    finite.plotFunction();

    /*NormFunction norm( -5, 5, "Outputs/data/MysteryData21100.txt");
    norm.plotData( data, 20 );
    norm.plotFunction();*/

    CauchyLorenzFunction cauch( -5, 5, "Outputs/data/MysteryData21100.txt" );
    cauch.plotData( data, 20 );
    cauch.plotFunction();

    return 0;
}