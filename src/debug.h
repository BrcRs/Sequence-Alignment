// #define DEBUGOK
#ifndef DEBUGOK
#define DEBUGOK
#define DEBUG() printf("\n%s, ligne %d\n", __PRETTY_FUNCTION__, __LINE__)

#else
#define DEBUG()

#endif
