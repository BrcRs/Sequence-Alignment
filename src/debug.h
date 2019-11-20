#ifndef DEBUG_H
#define DEBUG_H

#define DEBUGOK
#ifdef DEBUGOK
#define DEBUG() printf("\n[%s:%s], l%d : ", __FILE__, __PRETTY_FUNCTION__, __LINE__)
#define DEBUGX(x) printf("\n[%s:%s] l%d : %s\n", __FILE__ ,__PRETTY_FUNCTION__, __LINE__, x)

#else
#define DEBUG()
#define DEBUGX(x)

#endif
#endif
