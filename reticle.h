#ifndef RETICLE_INCLUDED
#define RETICLE_INCLUDED

#include <algorithm>
#include <array>
#include <cstdlib>
#include <random>
#include<iostream>
namespace grid
{
void seedGenerator();
template <class It>
void printArray(It begin, It end);
template <typename It>
void reticleInit(It Begin, It End, char mode);
template <typename It>
void linkInit(It Begin, It End);
int bernoulli(void);
double normal(void);
}




template <class It>
void grid::printArray(It begin,It end)
{
        while(begin != end)
        {
                    std::cout << *begin << ' ';
                            ++begin;
        }
            std::cout << std::endl;
}
#endif // RETICLE_INCLUDED

