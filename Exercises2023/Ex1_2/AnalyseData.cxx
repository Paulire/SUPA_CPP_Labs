// Created by: Paul M Ireland
// Date: 15/11/2023

#include <iostream>
#include <fstream>  // File i/o
#include <vector>

#define vector2d vector < vector <double> >

using namespace std;

vector2d read_file( string );
void print_vector( int );

int main( )
{
        vector2d data = read_file( "./input2D_float.txt" );

        return 0;
}

// Reads a file and returns the x,y vector
vector2d read_file( string f_name )
{
        // Open file of floats
        fstream FileObj;
        FileObj.open( f_name );
        if ( FileObj.fail() ) {
                cout << "Error: could not load file...\n";
                exit(-1);
        }

        // Displayes contained data for input file to terminal
        // Temporty stores file data
        int num_lines;
        string line_cache;
        string number_cache;
        vector2d data;

        // Loop through lines of file
        FileObj >> line_cache;
        for ( int i=0; !FileObj.eof(); i++ ) {
                // Gets number before comma
                getline( FileObj, number_cache, ',' );
                if ( !FileObj.eof() ) {
                        // Converts from string to double and stores in vector
                        data.push_back( vector<double> {stod( number_cache )} );
                        getline( FileObj, number_cache, '\n' );
                        data[i].push_back( stod( number_cache ) );
                }
                else
                        num_lines = i;

        }

        FileObj.close();

        cout << "There are " << num_lines << " lines\n";

        return data;
}
