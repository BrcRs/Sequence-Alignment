#include "tools.h"

int main()
{
  char x[] = "12345";
  char y[] = "A G T A G";
  printf("\ntools_suppressChar(%s, %s, ' ') : \"%s\" ->", x, y, y);
  tools_suppressChar(x, y, ' ');
  printf("\"%s\"\n",  x );
  return 0;
}
