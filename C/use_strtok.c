#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char input[] = "a b c,d"; // input can't be "char *" type
  char * p;
  
  p = strtok(input, " ,"); // the first use of strtok
  while(p!=NULL)
  {
      printf("%s\n", p);
      p = strtok(NULL, " ,"); // the second use of strtok
  }

  return 0;
}
