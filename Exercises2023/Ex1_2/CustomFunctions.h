#pragma once

#include <fstream>  // File i/o
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// Simplfy 2D vector declirations
#define vector2d vector < vector <double> >

vector2d read_file( string );
void print_vector( vector2d, int );
vector<double> get_magnitude( vector2d );
vector<double> least_square( vector2d );
