#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "lib/mathlib.h"
#include <stdio.h>
#include <memory.h>

char getoptChar(int argc, char **argv)
{
  extern char *optarg;
  char opt;
  printf("%c", opt);
  while ((opt = getopt(argc, argv, "f:asm")) != -1)
  {
    switch (opt)
    {
    case 'm':
      return 'a';

    case 's':
      return 'b';

    default:
      break;
    }
  }
  return '0';
}

int main(int argc, char **argv)
{
  int a, b, c, wynik;
  // printf("a = POLE PROSTOKATA | b = POLE TRÓJKATA | c = ls -al | d = pwd \n");
  char liczba = getoptChar(argc, argv), command[100], opcja;

  char folder[100];
  char mk[100];
  if (liczba == 'a')
  {
    printf("a = POLE PROSTOKATA | b = POLE TRÓJKATA \n");
    printf("WYBIERZ ZADANIE a/b: \n");
    scanf("%s", &opcja);
    printf("PODAJ 2 LICZBY: ");
    scanf("%i %i", &a, &b);

    switch (opcja)
    {
    case 'a':
      printf("POLE PROSTOKATA: ");
      wynik = prostokat(a, b);
      break;
    case 'b':
      printf("POLE TRÓJKATA: ");
      wynik = trojkat(a, b);
      break;
    default:
      printf("%s\n", "COS POSZLO NIE TAK!");
      return -1;
    }
  }
  if (liczba == 'b')
  {
    printf("c = ls -al | d = pwd \n");
    printf("WYBIERZ ZADANIE c/d:  \n");
    scanf("%s", &opcja);
    switch (opcja)
    {
    case 'c':
      strcpy(command, "ls -al");
      system(command);
      return 0;
    case 'd':
      strcpy(command, "pwd");
      system(command);
      return 0;
    default:
      printf("%s\n", "COS POSZLO NIE TAK!");
      return -1;
    }
  }
  printf("%i\n", wynik);
  return 0;
}
