#include "CustomFunctions.h"

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

void print_vector( vector2d data, int N )
{
        if ( N > data.size() ) {
                cout << "Warning: N is greater than the number of line, setting N=3" << endl;
                N = 3;
        }

        for( int i=0; i<N; i++ ) {
                cout << data[i][0] << " " << data[i][1] << endl;
        }
}

// Computes the megniude of a set of vectors returned as a magnitude
vector<double> get_magnitude( vector2d data )
{
        cout << "Magnitudes" << endl;
        vector<double> abs;

        for( int i=0; i<data.size(); i++ ) {
                abs.push_back( sqrt( data[i][0]*data[i][0] + data[i][1]*data[i][1] ) );

                cout << abs[i] << endl;
        }


        return abs;
}

// Computes m and c for y=mx+c using least squre method
vector<double> least_square( vector2d data ) {

        // Calc avrages
        double y_avr = 0;
        double x_avr = 0;

        for ( vector<double> v : data ) {
                x_avr += v[0];
                y_avr += v[1];
        }
        x_avr /= data.size();
        y_avr /= data.size();

        // Get gradient
        double x_temp;
        vector<double> m_c = { 0, 0 };
        double numerator = 0;
        double denominator = 0;

        for ( vector<double> v : data ) {
                x_temp = x_avr - v[0];
                numerator += x_temp*( y_avr - v[1] );
                denominator += x_temp*x_temp;
        }
        m_c[0] = numerator/denominator; // m
        m_c[1] = y_avr - m_c[0]*x_avr;  // c

        return m_c;
}
