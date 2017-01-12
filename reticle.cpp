#include "reticle.h"
#include "definitions.h"
using namespace std;
#include <random>
extern std::default_random_engine generator;
std::bernoulli_distribution bd(0.5);
std::normal_distribution<double> gauss(JM,JS);

int grid::bernoulli(void){
    if (bd(generator)) {return 1;}
    else {return -1;};
}
double grid::normal(void){
    return gauss(generator);
}

//initialize the container by the mode up, down or random
template <typename It>
void grid::reticleInit(It Begin, It End, char mode){
    if (mode=='u') {
    std::cout << "initialize all up"<<std::endl;
    std::fill(Begin, End,1);
    }
    if (mode=='d') {
    std::cout << "initialize all down"<<std::endl;
    std::fill(Begin, End,0);}
    if (mode='r'){
    std::cout << "initialize all random"<<std::endl;
    std::generate(Begin, End,grid::bernoulli);}
}

template <typename It>
void grid::linkInit(It Begin, It End){
   std::generate(Begin, End, grid::normal);
}

template void grid::linkInit<double*>(double*,double*);
template void grid::reticleInit<int*>(int* ,int* , char);
template void grid::reticleInit<double*>(double* ,double* , char);
