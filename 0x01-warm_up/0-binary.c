#include "search_algos.h"

/**
 * binary_search - search for a value in a sorted arrsay using Binary Search algo
 *
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: the index where value is located
 */
int binary_search(int *array, size_t size, int value)
{
  int midpoint;
  size_t low, high;
  size_t i;

  if (array == NULL)
    return (-1);

  low = 0;
  high = size - 1;
  midpoint = (high - low) / 2;

  while (1)
  {
    printf("Searching in array: ");
    for (i = low; i < high; i++)
      printf("%d, ", array[i]);
    printf("%d\n", array[i]);
    
    if (high == low && array[midpoint] != value)
      return (-1);

    if (array[midpoint] == value)
      return (midpoint);
    else if (array[midpoint] > value)
      high = midpoint + 1;
    else if (array[midpoint] < value)
      low = midpoint + 1;
    midpoint = (high + low) / 2;
  }
  return (-1);
}
