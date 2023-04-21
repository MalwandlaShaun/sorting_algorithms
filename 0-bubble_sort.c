#include "sort.h"
/**
 * SwapFunc:- Function to swap int
 * 
 * @i: integer value
 * @j: integer value
 */

void SwapFunc(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * bubble_sort:- Function that sorts ints in ascending order
 *
 * @array: Array of integers
 * @size: size of Array
 */

void bubble_sort(int *array, size_t size)
{
	size_t x;
	size_t y;

	for(x = 0; x < size-1; ++x)
	{
		for(y = 0; y < size -x -1; ++y)
		{
			if (array[y] > array[y+1])
			{
				SwapFunc(&array[y], &array[y+1]);
			}
		}
	}
}
