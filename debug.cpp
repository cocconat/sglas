#include<iostream>
#include <algorithm>
#include <array>
#include <cstdlib>
#include <random>

#include "definitions.h"
#include "montecarlo.h"
#include "reticle.h"

//print array_configuration to std output
//#######################################
std::default_random_engine generator;

int main()
{
    std::array<int, N> R;
    std::array<double, N> J;
    int * site_array;
    site_array=new int[D];
    generator.seed(time(NULL));
    grid::reticleInit(R.begin(),R.end(), 'r');
    grid::reticleInit(J.begin(),J.end(), 'r');
//    grid::linkInit(J.begin(),J.end());
    grid::printArray(J.begin(), J.end());
    grid::printArray(R.begin(),R.end());
    mc::flipSite(R,site_array);
    double energy=mc::distanceEvaluation(R,J,site_array);
    std::cout << *site_array<< "   "<<energy<< std::endl;
};

//################
