#include "adnFiles.h"
#include "tools.h"
int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    printf("\n/!/ Nombre d'arguments invalide /!/\n");
    return 0;
  }
  if (strcmp(argv[1], "read_adnFILE") == 0)
  {

    // test des fonctions
    char *x = NULL;
    char *y = NULL;
    if (read_adnFILE(argv[2], NULL, NULL, &x, &y) != 0)
    {
      fprintf(stderr, "\nLe test de [read_adnFILE] a echoue\n");
    }
    printf("\nread_adnFILE %s NULL NULL ? ? :\nx = \"%s\"\ny = \"%s\"\n\n", argv[2], x, y);
  }

  return 0;
}
