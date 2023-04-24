#include "sort.h"
/**
 * swapFunc:- 'Function to swap integers'
 * @a: integer value
 * @b: integer value
 */

void swapFunc(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort:- 'Function to arrange integers in ascending order'
 * @array: Array of integers
 * @size: Size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, step;
	int min_idx;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (step = 0; step < size - 1; step++)
	{
		min_idx = step;
		for (i = step + 1; i < size; i++)
		{
			if (array[i] < array[min_idx])
			{
				min_idx = i;
			}
		}

		swapFunc(&array[min_idx], &array[step]);
		print_array(array, size);
	}
}
