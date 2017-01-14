#ifndef MONTECARLO_INCLUDED
#include <boost/multi_array.hpp>
typedef boost::multi_array<double, D> array_type;
typedef boost::multi_array<int, D> array_type_int;
#include "main.h"

namespace mc
{
double distanceEvaluation(const & array_type_int, const & array_type,const int*);
void flipSite(int*);
void montecarloStep(array_type_int & ,const array_type & );
int validateStep(double );
}
#endif
