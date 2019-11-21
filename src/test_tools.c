#include "tools.h"

int main(int argc, char** argv)
{
  switch (argc)
  {
    case 2 :
    if (strcmp(argv[1], "tools_suppressChar") == 0)
    {

      char x[] = "12345";
      char y[] = "A G T A G";
      printf("\ntools_suppressChar(\"%s\", \"%s\", ' ') : \"%s\" => ", x, y, y);
      tools_suppressChar(x, y, ' ');
      printf("\"%s\"\n",  x );
      break;
    }
    if (strcmp(argv[1], "tools_LS") == 0)
    {
      tools_LS(".");

      break;
    }

    break;


    default :
    printf("\nErreur : Arguments invalides\nExecutions possibles :\n\n./test_tools tools_suppressChar");
    printf("\n./test_tools tools_LS");
    printf("\n\n");
    break;
  }
  return 0;
}
