#include<iostream>
#include <algorithm>
#include <array>
#include <cstdlib>
#include <random>

#define N 10
#define JS 0.1
#define JM 1
using namespace std;

std::default_random_engine generator;
std::bernoulli_distribution bd(0.5);
std::normal_distribution<double> gauss(JM,JS);
//print array_configuration to std output
template <class ForwardIteratorType>
void printArray(ForwardIteratorType begin, ForwardIteratorType end)
{
        while(begin != end)
        {
                    std::cout << *begin << ' ';
                            ++begin;

        }
            std::cout << std::endl;

}

template <class It>
void reticle_init(It Begin, It End, char mode);
template <class It>
void link_init(It Begin, It End);
//#######################################
int main(){
    array<int, N> R;
    array<double, N> J;
    reticle_init(R.begin(),R.end(), 'r');
    link_init(J.begin(),J.end());
    printArray(J.begin(), J.end());
}
//######################################
int bernoulli(void){
    if (bd(generator)) {return 1;}
    else {return -1;};
}
double normal(void){
    return gauss(generator);
}

//initialize the container by the mode up, down or random
template <class It>
void reticle_init(It Begin, It End, char mode){

    if (mode=='u') {
    cout << "initialize all up"<<endl;
//    generate(Begin, End,bernoulli);
    }
    if (mode=='d') {
    cout << "initialize all down"<<endl;
    generate(Begin, End,bernoulli);}
    if (mode='r'){
    cout << "initialize all random"<<endl;
    generate(Begin, End, bernoulli);}
}

template <class It>
void link_init(It Begin, It End){
   generate(Begin, End, normal);
}
