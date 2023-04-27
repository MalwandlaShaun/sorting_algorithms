#include "sort.h"
/**
 * get_max_element:- 'Function to find maximum elemnt in array'
 * @array: array of integer values
 * @size: size of array
 *
 * Return: Maximum element in an array.
 */
int get_max_element(int *array, int size)
{
	int i, maximum_element;

	maximum_element = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > maximum_element)
			maximum_element = array[i];
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
		return;

	max = get_max_element(array, size);

	count_array = malloc(sizeof(int) * (max + 1));
	if (count_array == NULL)
		return;

	output_array = malloc(sizeof(int) * size);
	if (output_array == NULL)
	{
		free(count_array);
		return;
	}

	for (i = 0; i <= max; i++)
		count_array[i] = 0;

	for (i = 0; i < (int)size; i++)
		count_array[array[i]] += 1;

	for (i = 1; i <= max; i++)
		count_array[i] += count_array[i - 1];
	print_array(count_array, max + 1);

	for (i = size - 1; i >= 0; i--)
	{
		output_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output_array[i];

	free(count_array);
	free(output_array);
}
