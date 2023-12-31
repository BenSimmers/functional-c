#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ! TODO
// Fix memory management
// ;)

#ifndef _FUNCTIONAL_H_
#define _FUNCTIONAL_H_

typedef struct
{
  int hasValue;
  void *value;
} Option;

Option Some(void *value)
{
  Option option;
  option.hasValue = 1;
  option.value = value;
  return option;
}

Option None()
{
  Option option;
  option.hasValue = 0;
  return option;
}

typedef struct
{
  int isLeft;
  int isRight;
  void *value;
} Either;

Either Left(void *value)
{
  Either either;
  either.isLeft = 1;
  either.isRight = 0;

  char *error = malloc(sizeof(char) * 100);
  strcpy(error, (char *)value);
  either.value = error;

  return either;
}

Either Right(void *value)
{
  Either either;
  either.isLeft = 0;
  either.isRight = 1;
  either.value = value;
  return either;
}

typedef struct
{
  int *arr;
  int length;
  int capacity;
} Array;


Array map(int (*fn)(int), Array arr)
{
  Array result;
  result.arr = malloc(sizeof(int) * arr.length);
  result.length = 0;

  for (int i = 0; i < arr.length; i++)
  {
    result.arr[result.length] = fn(arr.arr[i]);
    result.length++;
  }
  return result;
}


Array filter(int (*fn)(int), Array arr)
{
  Array result;
  result.arr = malloc(sizeof(int) * arr.length);
  result.length = 0;

  for (int i = 0; i < arr.length; i++)
  {
    if (fn(arr.arr[i]))
    {
      result.arr[result.length] = arr.arr[i];
      result.length++;
    }
  }
  return result;
}


Array push(int value, Array arr)
{
  if (arr.length == arr.capacity)
  {
    // Increase capacity by *2
    arr.capacity *= 2;
    arr.arr = realloc(arr.arr, sizeof(int) * arr.capacity);
  }

  arr.arr[arr.length] = value;
  arr.length++;
  return arr;
}

int reduce(int (*fn)(int, int), int initial, Array arr)
{
  int result = initial;
  if (arr.length == 0)
  {
    return result;
  }

  for (int i = 0; i < arr.length; i++)
  {
    result = fn(result, arr.arr[i]);
  }
  return result;
}


#endif