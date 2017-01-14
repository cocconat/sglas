#include <cstdlib>
#include <random>
#include <algorithm>
#include <iostream>
#include <boost/multi_array.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_real_distribution.hpp>
#include <boost/random/uniform_int_distribution.hpp>//cons

#include "montecarlo.h"
#include "main.h"

extern boost::random::mt19937 gen;
boost::random::uniform_int_distribution<> randomSite(0, N);
boost::random::uniform_real_distribution<> uniDist(0, 1.0);

//Montecarlo step is composed from Distance Proposal and Evaluation.
//each function compose a part of Metropolis algorithm for a Spin Glass system
//it's not efficient, but it works
//Montecarlo_step is a meta function, it is a simple call for sglas
void mc::montecarloStep(array_type_int & reticle,const array_type & links){
    int* s;
    s= new int [D];
    mc:: flipSite(s);
    double energy=mc::distanceEvaluation(reticle,links,s);
    if (mc::validateStep(energy)){
        *(reticle+s)=-*(reticle+s);
    }
}
//Distance evaluation measure the energy between two different configuration
//it computes the difference only without estimate the whole reticle again

int mc:: validateStep(double energy){
    if (0 < energy){ return 0;}
    else{
        return floor(uniDist(gen)/exp(energy/T));}
}
void mc::flipSite(int* site_array){
    //chose a random site for each dimension
    for (int i=0; i<D; i++){
    *(site_array+i) = randomSite(gen);
    }
}
double mc::distanceEvaluation(const array_type_int& reticle,const array_type & links,const int *s){
    //measure the distance between two configuration:
    //take a look to links definition for a better understanding
    //it don't compute the whole reticle but the area adjacent to site_array
    //site_array is defined as s in this scope
    //energy is -2*Delta*U(site,adj) for each adjacent site
    double energy=0;
    for (int d=0; d<D; d++){
        for (int j=0; j<2; j++){
            energy+=-2*reticle[*(s+d)%N]*reticle[(*(s+d)-1+2*j)%N]*links[(*(s+d)+j)%N];
        }
    }
    return energy;
}



//template double mc::distanceEvaluation<N>(const array_type_int& , const array_type& ,const int *s);
//template void mc::flipSite<N> (const array_type_int , int* site_array);
//template void mc::montecarloStep<N>(array_type_int& ,const array_type& links);
