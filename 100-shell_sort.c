#include "sort.h"

/**
 * swapFunc - Function to swap integers
 * @a: The first integer to swap
 * @b: The second integer to swap
 */

void swapFunc(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort:- Using shell sort based on Knuth increment to ascend numbers in order
 * @array: Array of numbers
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	size_t interval;
	size_t a;
	size_t b;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (interval = 1; interval < (size / 3);)
	{
		interval = interval * 3 + 1;
	}

	for (;interval >= 1; interval /= 3)
	{
		for (a = interval; a < size; a++)
		{
			b = a;
			while (b >= interval && array[b - interval] > array[b])
			{
				swapFunc(array + b, array + (b - interval));
				b -= interval;
			}
		}
		print_array(array, size);
	}
}
