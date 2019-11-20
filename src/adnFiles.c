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
  // DEBUG();fprintf(stdout, "\nn = %d\nm = %d\n", n, m);
  *x = malloc(n * sizeof(char) );
  *y = malloc(m * sizeof(char) );

  char *x2 = malloc((n * 2 - 1) * sizeof(char) );
  char *y2 = malloc((m * 2 - 1) * sizeof(char) );

  // if (fscanf(f, " %s\n", x2) != 1)
  // if (tools_LineInFILE(&x2, f) != 0)
  // {
  //   fprintf(stderr, "\n[%s] Erreur : Lecture incorrecte : ligne trop grande\n", __PRETTY_FUNCTION__);
  //   fclose(f);
  //   exit(__LINE__);
  // }

  switch (tools_LineInFILE(&x2, f))
  {
    case 0 :
    break;

    case -1 :
    fprintf(stderr, "\n[%s] Erreur : Lecture incorrecte : ligne a lire trop grande\n", __PRETTY_FUNCTION__);
    fclose(f);
    exit(__LINE__);
    break;
    
    default :
    fprintf(stderr, "\n[%s] Erreur : Lecture incorrecte pour raison inconnue\n", __PRETTY_FUNCTION__);
    fclose(f);
    exit(__LINE__);


  }


  // if (fscanf(f, " %s\n", y2) != 1)
  if (tools_LineInFILE(&y2, f) != 0)
  {
    fprintf(stderr, "\n[%s] Erreur : Lecture incorrecte\n", __PRETTY_FUNCTION__);
    fclose(f);
    exit(__LINE__);
  }

  // DEBUG();printf("\nx2 = %s\ny2 = %s\n", x2, y2);

  tools_suppressChar(*x, x2, ' ' );
  tools_suppressChar(*y, y2, ' ' );
  // strcpy(*x, tools_suppressChar(*x, x2, ' ' ));
  // strcpy(*y, tools_suppressChar(*y, y2, ' ' ));

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
