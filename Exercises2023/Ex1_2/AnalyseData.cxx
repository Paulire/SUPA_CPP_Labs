// Created by: Paul M Ireland
// Date: 15/11/2023

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

#include "CustomFunctions.h"

int get_num_lines( )
{
        int n;
        cout << "How many lines?\n $ ";
        cin >> n;
        return n;
}

int main( )
{
        // Var
        int num_lines;
        vector2d data;
        int user_input;
        vector<double> exp;
        vector<double> mag;
        vector<double> m_g;
        ofstream f;
        string input_file_loc = "./input2D_float.txt";

        // Load file
        std::cout << "Loading file...";
        data = read_file( input_file_loc );
        std::cout << "Done!\n";

        // Preamble
        std::cout << "Would you like:\n\t (1) print file\n\t (2) calculate and print magnitudes\n\t (3) get fit (least squares method)\n\t (4) calulate x^y\n\t (9) to quit\n";
        std::cout << "Options 2,3,4 will produce an output text file of resaults.\n";

        // Main shell
        do {
                // Input
                std::cout << " $ ";
                std::cin >> user_input;

                switch (user_input)
                {
                // Print file
                case 1:
                        num_lines = get_num_lines( );
                        print( data, num_lines );
                        break;
                
                // Calcualte magnitude and print resault
                case 2:
                        mag = get_magnitude( data );
                        num_lines = get_num_lines( );
                        print( mag, num_lines );

                        write_file( "Outputs/abs_results.txt", mag );
                        break;
                
                // Get fit line +chi^2 paramiter and prints the answer and writes it to a flie
                case 3:
                        m_g = least_square( data );     // Returns [0] m, [1] c, [3] chi^2/NDF
                        cout << "y=" << m_g[0] << "x+" << m_g[1] << endl;
                        cout << "chi^2/NDF=" << m_g[3] << endl;
                        
                        f.open( "Outputs/fit_resaults.txt" );

                        f << "y=" << m_g[0] << "x+" << m_g[1] << endl;
                        f << "chi^2/NDF=" << m_g[3] << endl;

                        f.close();
                        break;

                // Get the x^y for each point and returns to STD and file
                case 4:
                        exp = power_vector( data );
                        num_lines = get_num_lines( );
                        print( exp, num_lines );

                        write_file( "Outputs/exp_results.txt", exp );
                        break;

                case 9:
                        break;
                
                default:
                        std::cout << "Unknown input" << endl;
                        break;
                }
        } while( user_input != 9 );

        return 0;
}

