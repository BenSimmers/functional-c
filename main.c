#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functional.h"

Option divide(int numerator, int denominator)
{
  if (denominator == 0)
  {
    return None();
  }
  else
  {
    int *result = malloc(sizeof(int));
    *result = numerator / denominator;
    return Some(result);
  }
}

Option return_string()
{
  char *str = malloc(sizeof(char) * 10);
  str[0] = 'H';
  str[1] = 'e';
  str[2] = 'l';
  str[3] = 'l';
  str[4] = 'o';
  str[5] = '\0';
  return Some(str);
}

Either divide_either(int numerator, int denominator)
{
  if (denominator == 0)
  {
    return Left("Cannot divide by zero");
  }
  else
  {
    int *result = malloc(sizeof(int)); 
    *result = numerator / denominator;
    return Right(result);
  }
}

Either return_string_either()
{
  char *str = malloc(sizeof(char) * 10);
  str[0] = 'H';
  str[1] = 'e';
  str[2] = 'l';
  str[3] = 'l';
  str[4] = 'o';
  str[5] = '\0';

  return Right(str);
}

int main()
{
  Option result = divide(10, 5);
  if (result.hasValue)
  {
    printf("Result: %d\n", *(int *)result.value);
  }
  else
  {
    printf("Cannot divide by zero\n");
  }

  return 0;
}
