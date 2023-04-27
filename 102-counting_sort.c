#include "sort.h"

/**
 * counting_sort:- Sort array using the counting sort
 *
 * @array: An array of integers
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int count_size;
	int max, min;
	size_t i;
	int *count_array;
	int *output_array;

	max = array[0], min = array[0];

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
		if (array[i] < min)
		{
			min = array[i];
		}
	}

	count_size = max - min + 1;
	count_array = (int *) malloc(count_size * sizeof(int));
	for (i = 0; i < (size_t)count_size; i++)
	{
		count_array[i] = 0;
	}

	for (i = 0; i < size; i++)
	{
		count_array[array[i] - min]++;
	}

	for (i = 1; i < (size_t)count_size; i++)
	{
		count_array[i] += count_array[i - 1];
	}

	output_array = (int *) malloc(size * sizeof(int));

	for (i = 0; i < size; i++)
	{
		output_array[count_array[array[i] - min] - 1] = array[i];
		count_array[array[i] - min]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = output_array[i];
	}

	print_array(output_array, max + 1);

	free(count_array);
	free(output_array);
}

