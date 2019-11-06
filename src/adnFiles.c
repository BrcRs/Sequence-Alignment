#include "adnFiles.h"


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Lit la taille et la valeur de deux mots d'un fichier .adn
*/
int read_adnFILE(char* filename, int* _n, int* _m, char** x, char** y)
{
  int n = 0, m = 0;

  FILE* f = fopen(filename, "r");
  if (f == NULL)
  {
    fprintf(stderr, "\n[%s] Erreur : Impossible d'ouvrir le fichier \"%s\"\n", __PRETTY_FUNCTION__, filename);
    // fclose(f);
    exit(__LINE__);
  }

  if (fscanf(f, " %d\n", &n) != 1)
  {
    fprintf(stderr, "\n[%s] Erreur : Lecture incorrecte\n", __PRETTY_FUNCTION__);
    fclose(f);
    exit(__LINE__);
  }

  if (fscanf(f, " %d\n", &m) != 1)
  {
    fprintf(stderr, "\n[%s] Erreur : Lecture incorrecte\n", __PRETTY_FUNCTION__);
    fclose(f);
    exit(__LINE__);
  }

  *x = malloc(n * sizeof(char) );
  *y = malloc(m * sizeof(char) );

  char *x2 = malloc((n * 2 - 1) * sizeof(char) );
  char *y2 = malloc((m * 2 - 1) * sizeof(char) );

  if (fscanf(f, " %s\n", x2) != 1)
  {
    fprintf(stderr, "\n[%s] Erreur : Lecture incorrecte\n", __PRETTY_FUNCTION__);
    fclose(f);
    exit(__LINE__);
  }

  if (fscanf(f, " %s\n", y2) != 1)
  {
    fprintf(stderr, "\n[%s] Erreur : Lecture incorrecte\n", __PRETTY_FUNCTION__);
    fclose(f);
    exit(__LINE__);
  }

  strcpy(*x, strtok( x2 ," "));
  strcpy(*y, strtok( y2 ," "));

  fclose(f);
  if (_n != NULL)
  {
    *_n = n;
  }

  if (_m != NULL)
  {
    *_m = m;
  }


  return 0;
}
