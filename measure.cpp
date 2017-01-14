#include "main.h"

template <class It>
double measure::magnetization(It begin, It end){
    int M=0;
    while (begin!= end)
    {
        M+= *begin;
    }
#if DEBUG>0
    std::cout << "magnetization is "<< M<< std::endl;
#endif
    return M;
}
template <size_t SIZE>
double measure::energy(const std::array<int,SIZE>& reticle,const std::array<double,N>){
    double E=0;
    for (int i=0;i<N;i++){

    }
    return M;
}
template int measure::magnetization<int*> (int* begin, int*  end);
template double mieasure::energy<N>(const std::array<int,N>& reticle,const std::array<double,N>){
