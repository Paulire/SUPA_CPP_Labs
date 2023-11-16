// Created by: Paul M Ireland
// Date: 15/11/2023

#include <iostream>
#include <cstring>
#include <fstream>

#include "CustomFunctions.h"

using namespace std;

// Declerations

int main( )
{
        // Load data from file
        vector2d data = read_file( "./input2D_float.txt" );

        char user_input[20];
        cout << "Would you like [print] or display [mag]nitude? ";
        cin >> user_input;

        // Print vectors 
        if ( strcmp( "print", user_input ) == 0 ){
                int no_lines;
                cout << "How many line? ";
                cin >> no_lines;

                print_vector( data, no_lines );
        }

        // Calulate each vectors magnitude
        if ( strcmp( "mag", user_input ) == 0 || strcmp( "magnitude", user_input ) == 0 ) {
                vector<double> abs = get_magnitude( data );
        }

        // Calulates best fit LSM
        vector <double> m_c = least_square( data );

        cout << "Best fit: " << "\n\ty=" << m_c[0] << "x+" << m_c[1] << endl;

        // Save fit output
        ofstream File_out( "line_out.txt" );
        if ( File_out.fail() ) {
                cout << "Error: could not load file...\n";
                exit(-1);
        }

        File_out << "Best fitline\ny=" << m_c[0] << "x+" << m_c[1];
        File_out.close();

        return 0;
}

