#include "sort.h"

/**
 * get_max_element:- function to find maximum elemnt in array
 * @array: array of integer values
 * @size: size of array
 *
 * Returns: Maximum element in an array.
 */
int get_max_element(int *array, int size)
{
	int maximum_element;
	int i;

	maximum_element = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > maximum_element)
		{
			maximum_element = array[i];
		}
	}
	return (maximum_element);
}

/**
 * counting_sort:- function to sort numbers
 * @array: array of integer numbers
 * @size: size of array
 *
 * Returns: Sorted array
 */
void counting_sort(int *array, size_t size)
{
	int i, max, *output_array, *count_array;

	if (array == NULL || size < 2)
	{
		return;
	}

	/* Determine the maximum element in the array */
	max = get_max_element(array, size);

	/* Allocat memory for the count array */
	count_array = malloc(sizeof(int) * (max + 1));
	if(count_array == NULL)
	{
		return;
	}

	/* Allocate memory for output array. */
	output_array = malloc(sizeof(int) * size);
	if(output_array == NULL)
	{
		free(count_array);
		return;
	}

	for (i = 0; i <= max; i++)
	{
		count_array[i] = 0;
	}

	/* Store the count of each element in count_array */
	for (i = 0; i < (int)size; i++)
	{
		count_array[array[i]] += 1;
	}


	/* Compute the cumulative sum of the counts in the count array. */
	for (i = 1; i <= max; i++)
	{
		count_array[i] += count_array[i - 1];
	}
	print_array(count_array, max + 1);

	/* Construct the output array by placing each element in its position */
	for (i = size - 1; i >= 0; i--)
	{
		output_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	/* Copy the output array back into the input array */
	for (i = 0; i < (int)size; i++)
	{
		array[i] = output_array[i];
	}

	/* Free the memory */
	free(count_array);
	free(output_array);
}
