#include<iostream>
#include <algorithm>
#include <array>
#include <cstdlib>
#include <random>
#include "montecarlo.h"
#include "definitions.h"
#include "reticle.h"

extern std::default_random_engine generator;
std::uniform_int_distribution<int> randomSite(0,N);
std::uniform_real_distribution<double> uniDist(0,1);

//Montecarlo step is composed from Distance Proposal and Evaluation.
//each function compose a part of Metropolis algorithm for a Spin Glass system
//it's not efficient, but it works
//Montecarlo_step is a meta function, it is a simple call for sglas
template <std::size_t SIZE>
void mc::montecarloStep( std::array<int,SIZE>& reticle,const std::array<double,SIZE>& links){
    int* site_array;
    site_array = new int [D];
    mc::flipSite(reticle,site_array);
    double energy=mc::distanceEvaluation(reticle,links,site_array);
    int move=mc::validateStep(energy);
    if (move){reticle[*site_array]=-reticle[*site_array];}
}

//Distance evaluation measure the energy between two different configuration
//it computes the difference only without estimate the whole reticle again

int mc:: validateStep(double energy){
    if (0 < energy){ return 0;}
    else{
        return floor(uniDist(generator)/exp(energy/T));}
}
template<std::size_t SIZE>
void mc::flipSite(const std::array<int,SIZE>& reticle, int* site_array){
    //chose a random site for each dimension
    for (int i=0; i<D; i++){
    *(site_array+i) = randomSite(generator);
    }
}
template <std::size_t SIZE>
double mc::distanceEvaluation(const std::array<int,SIZE>& reticle,const std::array<double,SIZE>& links,const int *s){
    //measure the distance between two configuration:
    //take a look to links definition for a better understanding
    //it don't compute the whole reticle but the area adjacent to site_array
    //site_array is defined as s in this scope
    //energy is -2*Delta*U(site,adj) for each adjacent site
    double energy=0;
    for (int d=0; d<D; d++){
        for (int j=0; j<2; j++){
            energy+=    -2*reticle[*(s+d)%SIZE]*reticle[(*(s+d)-1+2*j)%SIZE]*links[(*(s+d)+j)%SIZE];
        }
    }
    return energy;
}



template double mc::distanceEvaluation<N>(const std::array<int,N>& reticle, const std::array<double,N>& links,const int *s);
template void mc::flipSite<N> (const std::array<int,N>& reticle, int* site_array);
template void mc::montecarloStep<N>( std::array<int,N>& reticle,const std::array<double,N>& links);
