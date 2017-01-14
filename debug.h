#ifdef DEBUG
#include <cstdlib>
#include <iostream>
#if (DEBUG > 0) && (DEBUG < 2)
//std::cout<<"Debugging level 1";
#endif

#if (DEBUG > 1) && (DEBUG < 3)
//std::cout<<"Debugging level 2";
#endif

#if (DEBUG > n-1) && (DEBUG < n)
//std::cout"Debugging level n";
#endif
#endif
