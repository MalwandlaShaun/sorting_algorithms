#include "sort.h"
/**
 * bitonic_sort:- Function to sort array
 * @array: array
 * @size: size of array
 *
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	int *temp;

	temp = malloc(size * sizeof(int));
	if (temp == NULL)
	{
		printf("Error: Memory allocation failed");
		return;
	}
	bitonic_sort_helper(array, 0, size, 1, temp);
	free(temp);
}


/**
 * bitonic_sort_helper:- Function to help swap and sort bitonic sort
 * @array: array
 * @count: integer count value
 * @direction: direction to switch integer
 * @temp: pointer to temporary array
 *
 * Return: void
 */

void bitonic_sort_helper(int *array, size_t start, size_t count, int direction,
		int *temp)
{
	size_t i, k;
	char *dir_str;
	int new_direc;

	if (count > 1)
	{
		i = start;
		k = count / 2;
		bitonic_sort_helper(array, start, k, 1, temp);
		bitonic_sort_helper(array, start + k, k, 0, temp);
		bitonic_merge(array, start, count, direction, temp);

		if (direction == 1)
		{
			dir_str = "UP";
		}
		else
		{
			dir_str = "DOWN";
		}


		new_direc = array[start] < array[start + count - 1] ? 1 : 0;
		if (new_direc == 1)
		{
			dir_str = "UP";
		}
		else
		{
			dir_str = "DOWN";
		}

		printf("Merging [%d/%d] (%s)\n", array[i], array[k + 1], dir_str);
		printf("Result [%d/%d] (%s)\n", array[start], array[count], dir_str);
		for (i = start; i < start + count; i++)
		{
			printf("%d ", array[i]);
		}
		printf("\n");
	}
}

/**
 * bitonic_merge:- function to merge shifted bits
 * @array: array of integers
 * @start: start point
 * @count: integer count value
 * @direction: direction to shift bit
 * @temp: temporary array
 *
 * Return: void
 */

void bitonic_merge(int *array, size_t start, size_t count,
		int direction, int *temp)
{
	size_t i, k;
	int temp_val;

	if (count > 1)
	{
		k = count / 2;

		for (i = start; i < start + k; i++)
		{
			if (direction == (array[i] > array[i + k]))
			{
				temp_val = array[i];
				array[i] = array[i + k];
				array[i + k] = temp_val;
			}
		}
		bitonic_merge(array, start, k, direction, temp);
		bitonic_merge(array, start + k, k, direction, temp);
	}
}
