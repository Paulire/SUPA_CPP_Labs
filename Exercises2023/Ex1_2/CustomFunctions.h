#pragma once

#include <fstream>  // File i/o
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// Simplfy 2D vector declirations
#define vector2d vector < vector <double> >

vector<double> get_magnitude( vector2d );
vector<double> least_square( vector2d );
double power( double, double );
vector<double> power_vector( vector2d );

vector2d read_file( string );
void write_file( string, vector2d );
void write_file( string, vector<double> );

void print( vector2d, int N );
void print( vector<double>, int N );
void __print_check_size__( int, int* );
