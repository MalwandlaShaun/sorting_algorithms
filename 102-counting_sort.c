#include "sort.h"
/**
 * max_element:- Get maximum element in array
 * @array: An array of integers
 * @size: size of the array
 *
 * Return: The max integer
 */
int get_max_element(int *array, int size)
{
	int maximum_element, i;

	for (maximum_element = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maximum_element)
		{
			maximum_element = array[i];
		}
	}

	return (maximum_element);
}


/**
 * counting_sort:- Sort array using the counting sort
 *
 * @array: An array of integers
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max;
	int i;
	int *count_array;
	int *output_array;

	if (array == NULL || size < 2)
	{
		return;
	}

	output_array = malloc(sizeof(int) * size);
	if (output_array == NULL)
	{
		return;
	}
	max = get_max_element(array, size);
	count_array = malloc(sizeof(int) * (max + 1));
	if (count_array == NULL)
	{
		free(output_array);
		return;
	}

	for (i = 0; i < (max + 1); i++)
	{
		count_array[i] = 0;
	}

	for (i = 0; i < (int)size; i++)
	{
		count_array[array[i]] += 1;
	}

	for (i = 0; i < (max + 1); i++)
	{
		count_array[i] += count_array[i - 1];
	}
	print_array(count_array, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		output_array[count_array[array[i]] -1] = array[i];
		count_array[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
	{
		array[i] = output_array[i];
	}

	free(count_array);
	free(output_array);
}

