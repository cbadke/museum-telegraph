#include <stdio.h>

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    printf("argc = %d\n", argc);
    printf("Invalid arg. Enter a dot-dash pattern\n");
    return -1;
  }

  int i = 0;
  char* pattern = argv[1];
  while( pattern[i] != '\0' )
  {
    if (pattern[i] != '.'//dot
        && pattern[i] != '-'//dash (2.)
        && pattern[i] != ' '//gap (.)
        && pattern[i] != '_'//long dash (3.)
        && pattern[i] != '='//really long dash (5.)
       )
    {
      printf("found character '%c'\n", pattern[i]);
      printf("Pattern must only include . - _ = or ' '.\n");
      return -1;
    }
    i++;
  }

  unsigned int num = 0;
  for(--i; i >= 0; i--)
  {
    if (num & 0x80000000)
    {
      printf("Pattern too long for a single int to hold.\n");
      return -2;
    }

    if (pattern[i] == '.')
    {
      num <<= 1;
      num ^= 0b1;
    }
    else if (pattern[i] == '-')
    {
      num <<= 1;
      num ^= 0b1;
      num <<= 1;
      num ^= 0b1;
    }
    else if (pattern[i] == ' ')
    {
    }
    else if (pattern[i] == '_')
    {
      num <<= 1;
      num ^= 0b1;
      num <<= 1;
      num ^= 0b1;
      num <<= 1;
      num ^= 0b1;
      num <<= 1;
      num ^= 0b1;
    }
    else if (pattern[i] == '=')
    {
      num <<= 1;
      num ^= 0b1;
      num <<= 1;
      num ^= 0b1;
      num <<= 1;
      num ^= 0b1;
      num <<= 1;
      num ^= 0b1;
      num <<= 1;
      num ^= 0b1;
    }

    if (i != 0)
    {
      num <<= 1;
    }
  }

  printf("%u\n", num);

  return 0;
}
