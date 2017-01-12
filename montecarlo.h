#ifndef MONTECARLO_INCLUDED
#define MONTECARLO_INCLUDED
namespace mc
{
//template <class It>
//void montecarloStep(const It & reticle,const It & links,void (*f) distance_evaluation );
template <std::size_t SIZE>
double distanceEvaluation(const std::array<int,SIZE>&, const std::array<double,SIZE>&,const int *s);
template <std::size_t SIZE>
void flipSite(const std::array<int,SIZE>& reticle, int* site_array);
template <std::size_t SIZE>
void montecarloStep( std::array<int,SIZE>& reticle,const std::array<double,SIZE>& links);
int validateStep(double);
}

#endif
