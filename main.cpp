#include "main.h"
#include <boost/multi_array.hpp>
#include <boost/random/mersenne_twister.hpp>

typedef boost::multi_array<double, D> array_type;
typedef boost::multi_array<int, D>      array_type_int;

boost::random::mt19937 gen;

int main()
{

#if D==1
        array_type_int R(boost::extents[N]);
        array_type J(boost::extents[N]);
#endif
/*
#if D==2
        array_type_int R(boost::extents[N][N]);
        array_type J(boost::extents[N][N]);
#endif
#if D==3
        array_type_int R(boost::extents[N][N][N]);
        array_type J(boost::extents[N][N][N]);
#endif
*/
    gen.seed(time(NULL));
    int * site_array;
    site_array=new int[D];
//reticle initialization
    grid::reticleInit(R.data(),R.data()+R.size(), 'r');
    grid::linkInit(J.data(),J.data()+J.size());
    mc::montecarloStep(R,J);
#if DEBUG>3
    grid::printArray(A.data(),A.data()+A.size());
#endif
    for (int i; i<100;i++){
     mc::montecarloStep(R,J);
#if DEBUG>3
      //  if (i%10==0){grid::printArray(R.begin(),R.end());}
#endif
    }
};

//################
