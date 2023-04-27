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
	int j, max, *output_array, *count_array;
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* Allocate memory for output array. */
	output_array = malloc(sizeof(int) * size);
	if (output_array == NULL)
		return;

	/* Determine the maximum element in the array */
	max = get_max_element(array, size);

	/* Allocat memory for the count array */
	count_array = calloc(max + 1, sizeof(int));
	if (count_array == NULL)
		free(output_array);
		return;

	/* Count the number of occurrences of each element in the array */
	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	/* Compute the cumulative sum of the counts in the count array. */
	for (j = 1; j <= max; j++)
		count_array[j] += count_array[j - 1];
	print_array(count_array, max + 1);

	/* Construct the output array by placing each element in its position */
	for (j = size - 1; j >= 0; j--)
		output_array[--count_array[array[j]]] = array[j];

	/* Copy the output array back into the input array */
	for (i = 0; i < size; i++)
		array[i] = output_array[i];

	/* Free the memory */
	free(count_array);
	free(output_array);
}
