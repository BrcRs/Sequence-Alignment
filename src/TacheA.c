

#include "TacheA.h"

int csub(char x_i, char y_i)
{
  printf("\n[csub %c %c] ...", x_i, y_i);
  if (x_i == y_i)
  {
    DEBUG();
    printf("\n[csub %c %c] 0 ...ok", x_i, y_i);

    return 0;
  }
  if ((x_i == 'A' && y_i == 'T') || (x_i == 'G' && y_i == 'C') || (x_i == 'C' && y_i == 'G') || (x_i == 'T' && y_i == 'A'))
  {
    DEBUG();
    printf("\n[csub %c %c] 3 ...ok", x_i, y_i);

    return 3;
  }
  printf("\n[csub %c %c] 4 ...ok", x_i, y_i);
  return 4;
}




int DIST_NAIF_REC (char** x, char** y, int i, int j, int c, int dist)
{
  // Enumerer tous les alignements possibles de deux mots x et y
  printf("\n[DIST_NAIF_REC %s %s %d %d %d %d] ...", *x, *y, i, j, c, dist);
  // sleep(1);
  // printf("\n*x[0] = %c", x[0][0]);
  // printf("\n*x[1] = %c", x[0][1]);
  // printf("\n*x[2] = %c", x[0][2]);
  // printf("\n*x[3] = %c", *(x[strlen(*x - 1)]));
  printf("\nstrlen(*x) = %ld", strlen(*x));

  DEBUG();
  if (i>=strlen(x[0]) && j>=strlen(y[0]) )
  {
    printf("\n/!/ i = %d, j = %d", i, j);
    DEBUG();
    if (dist == INFINI || c < dist)
    {
      DEBUG();
      dist = c;
    }
  }
  else
  {
    DEBUG();
    if (i < strlen(*x) && j < strlen(*y))
    {
      printf("\nCas 1");
      printf("\ni = %d, j = %d", i, j);
      DEBUG();
      dist = DIST_NAIF_REC(x, y, i+1, j+1, c + csub(x[0][i], y[0][j]), dist );
    }
    if (i < strlen(*x))
    {
      printf("\nCas 2 : i=%d < strlen(*x)=%ld", i, strlen(*x));

      DEBUG();
      dist = DIST_NAIF_REC(x, y, i+1, j, c + C_DEL, dist);
    }
    if (j < strlen(*y))
    {
      printf("\nCas 3");

      DEBUG();
      dist = DIST_NAIF_REC(x, y, i, j+1, c + C_INS, dist);
    }

  }
  printf("\n[DIST_NAIF_REC %s %s %d %d %d %d] ...ok", *x, *y, i, j, c, dist);

  return dist;
}

int DIST_NAIF(char** x, char** y)
{

  return DIST_NAIF_REC(x, y, 0, 0, 0, INFINI);
}


int main(int argc, char* argv[])
{
  if (argc == 3)
  {
    // printf("\n%d\n", 'A');
    char* arg1 = argv[1];
    char* arg2 = argv[2];
    printf("\n\nDIST_NAIF(%s, %s) = %d\n\n", arg1, arg2, DIST_NAIF(&arg1, &arg2) );
    return 0;
  }
  if (argc == 2)
  {
    int n;
    int m;
    char* x;
    char* y;
    if (read_adnFILE(argv[1], &n, &m, &x, &y) != 0)
    {
      printf("\nErreur lors de la lecture d'un adnFile");
      return 0;
    }
    printf("\nn = %d, m = %d, x = %s, y = %s\n", n, m, x, y);

    return 0;
  }
  printf("\nErreur : nombre d'arguments invalide\n");
  return 0;
}
