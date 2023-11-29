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

        return data;
}

// Writes f_name file of datatype 2D vector
void write_file( string f_name, vector2d data )
{
        ofstream FileObj;
        FileObj.open( f_name );

        for ( vector<double> v : data )
                FileObj << v[0] << " " << v[1] << endl;

        FileObj.close();
}

// Writes f_name file of datatype 1D vector
void write_file( string f_name, vector<double> data )
{
        ofstream FileObj;
        FileObj.open( f_name );

        for ( double v : data )
                FileObj << v << endl;

        FileObj.close();
}

// Computes the megniude of a set of vectors returned as a magnitude
vector<double> get_magnitude( vector2d data )
{
        vector<double> abs;

        for( int i=0; i<data.size(); i++ ) {
                abs.push_back( sqrt( data[i][0]*data[i][0] + data[i][1]*data[i][1] ) );
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
        vector<double> m_c = { 0, 0, 0 };
        double numerator = 0;
        double denominator = 0;

        // Checks each data point and determines the numerator and denomin
        for ( vector<double> v : data ) {
                x_temp = x_avr - v[0];
                numerator += x_temp*( y_avr - v[1] );
                denominator += x_temp*x_temp;
        }
        m_c[0] = numerator/denominator; // m
        m_c[1] = y_avr - m_c[0]*x_avr;  // c

        vector2d errors = read_file( "error2D_float.txt" );

        // Chi square calulation
        double chi_2 = 0;
        string a;
        for ( int i=0; i<data.size(); i++ ) {
                chi_2 += pow( data[i][1] - ( m_c[0]*data[i][0]+m_c[1]),
                            2 )/pow( errors[i][0], 2 );
        }

        m_c[2] = chi_2/2;

        return m_c;
}

// Takes data and gets x^int(y)
vector<double> power_vector( vector2d data )
{
        vector<double> out;

        for( int i=0; i<data.size(); i++ ) {
                out.push_back(
                        power( data[i][0], data[i][1] )
                );
        }

        return out;
}

// Redo of pow
double power( double x, double exp )
{
        // Makes exponent int
        int exp_int = round( exp );

        if (exp_int == 0 ) {
                return 1;
        }

        return x*power( x, (float) exp_int-1 ); // Not a loop, just a recursive function call :D
}

// Prints N data points
void print( vector2d data, int N )
{
        // If N>num_lines: N=5
        __print_check_size__( data.size(), &N );

        for( int i=0; i<N; i++ ) {
                cout << data[i][0] << " " << data[i][1] << endl;
        }
}

// Same as before except takes double
void print( vector<double> data, int N )
{
        __print_check_size__( data.size(), &N );

        for( int i=0; i<N; i++ )
        {
                cout << data[i] << endl;
        }
}

// Checks if print line num is greater than the total number of line
void __print_check_size__( int size_data, int * N )
{
        if ( *N > size_data ) {
                *N = 5;
                cout << "Warning: Number of lines is greater than the total number of lines in file, setting N=" << *N << endl;
        }
}