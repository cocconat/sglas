#include <array>
#include <cstdlib>
#include <random>
#include <algorithm>
#include <iostream>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/bernoulli_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>

#include "reticle.h"

extern boost::random::mt19937 gen;
//insert bernoulli e gauss!!
boost::random::bernoulli_distribution<int> bd(0.5);
boost::random::normal_distribution<double> gauss(JM,JS);

int grid::bernoulli(void){
    if (bd(gen)) {return 1;}
    else {return -1;};
}
double grid::normal(void){
    return gauss(gen);
}

//initialize the container by the mode up, down or random
template <typename It>
void grid::reticleInit(It Begin, It End, char mode){
    if (mode=='u') {
#if DEBUG
    std::cout << "initialize all up"<<std::endl;
#endif
    std::fill(Begin, End,1);
    }
    if (mode=='d') {
#if DEBUG
    std::cout << "initialize all down"<<std::endl;
#endif
    std::fill(Begin, End,0);}
    if (mode='r'){
#if DEBUG
    std::cout << "initialize all random"<<std::endl;
#endif
    std::generate(Begin, End,grid::bernoulli);}
}

template <typename It>
void grid::linkInit(It Begin, It End){
   std::generate(Begin, End, grid::normal);
}

template void grid::linkInit<double*>(double*,double*);
template void grid::reticleInit<int*>(int* ,int* , char);
template void grid::reticleInit<double*>(double* ,double* , char);
