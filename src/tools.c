#include "tools.h"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Renvoie une nouvelle chaine de caractere qui est une copie de < char* src >
* mais sans son extension.
*/
char* tools_basename( char* src)
{
  if (src == NULL)
  {
    fprintf(stderr, "\nERREUR : chaine nulle");
    exit(EXIT_FAILURE);
  }
  int i = 0;
  while (src[i] != '\0')
  {
    i++;
  }
  while (i >= 0)
  {
    if (src[i] == '.')
    {
      break;
    }
    i--;
  }
  if (i < 0)
  {
    return NULL;
  }

  char* dest = (char*)malloc( sizeof(char) * i);
  strncpy(dest, src, i);
  dest[i] = '\0';
  return dest;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Lit une ligne du fichier specifie, stocke le resultat dans char* line, sans
* retour a la ligne ('\n').
* Retourne 0 si tout se passe bien. -1 est retourne si la taille de la ligne
* lue est trop grande (superieure a la variable locale MAX).
* Retourne 1 si buffer est different du resultat attendu.
*/
int tools_LineInFile(char* line, char* filename)
{

  FILE* f = fopen(filename, "r");

  int MAX = 255;
  char buffer[MAX];
  char c;
  int i;
  do
  {
    c = fgetc(f); // Does not read right character
    i = 0;
    while(c != '\n' && c != EOF)
    {
      if (i > MAX)
      {
        return -1;
      }
      buffer[i] = c;
      c = fgetc(f);
      i++;
    }
    buffer[i] = '\0';
    /* ??? */
    // if (!strcmp(buffer, line))
    // {
    //   fclose(f);
    //   return 1;
    // }
  }
  while(c != EOF);


  fclose(f);

  strcpy(line, buffer);
  return 0;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Lit une ligne du fichier specifie, stocke le resultat dans char* line, sans
* retour a la ligne ('\n').
* Retourne 0 si tout se passe bien. -1 est retourne si la taille de la ligne
* lue est trop grande (superieure a la variable locale MAX).
*/
int tools_LineInFILE(char** line, FILE* f)
{

  // FILE* f = fopen(filename, "r");

  int MAX = 255;
  char buffer[MAX];
  char c;
  int i;
  // do
  // {
    c = fgetc(f); // Does not read right character
    // DEBUG();printf("c = \'%c\'\n", c);
    i = 0;
    while(c != '\n' && c != EOF)
    {
      if (i > MAX)
      {
        return -1;
      }
      buffer[i] = c;
      // DEBUG();printf("c = \'%c\'\n", c);
      // DEBUG();printf("buffer[%d] = \'%c\'\n", i, buffer[i]);
      c = fgetc(f);

      i++;
    }
    buffer[i] = '\0';

  // }
  // while(c != EOF);

  // DEBUG();printf("buffer = %s", buffer);
  // fclose(f);

  strcpy(*line, buffer);
  // DEBUG();printf("*line = %s", *line);

  return 0;
}


int tools_countZerosInTab(int * tab, int size)
{
  int ans = 0;
  int i;
  for (i = 0 ; i < size ; i++)
  {
    ans += tab[i] == 0 ? 1 : 0;
  }

  return ans;
}

char* tools_suppressChar(char* dest, char* src, const char sup )
{
  // printf("\n\'%c\'\n\n", src[1]);
  // printf("\n\'%c\'\n\n", dest[1]);
  int i = 0;
  int j = 0;
  while (src[i] != '\0')
  {

    if (src[i] != sup)
    {
      // printf("\ni=%d, j=%d, sup=\'%c\'", i, j, sup);
      // printf("\n%c\n\n", src[i]);
      // printf("\n%c\n\n", dest[j]);

      dest[j] = src[i];
      // dest[j] = 'I';
      j++;
    }

    i++;
  }
  // printf("\ndest[j=%d] = \'\0\'\n\n", j);
  dest[j] = '\0';

  // return dest + j;
  return NULL;
}
