#include "sort.h"
void bitonic_sort(int *array, size_t size)
{
	int *temp = malloc(size * sizeof(int));
	if (temp == NULL)
	{
		printf("Error: Memory allocation failed");
		return;
	}
	print_array(array, size);
	bitonic_sort_helper(array, 0, size, 1, temp);
	free(temp);
}

void bitonic_sort_helper(int *array, size_t start, size_t count, int direction, int *temp)
{
	if (count > 1)
	{
		size_t k = count / 2;
		bitonic_sort_helper(array, start, k, 1, temp);
		bitonic_sort_helper(array, start + k, k, 0, temp);
		bitonic_merge(array, start, count, direction, temp);
	}
}

void bitonic_merge(int *array, size_t start, size_t count, int direction, int *temp)
{
	if (count > 1)
	{
		size_t k = count / 2;
		size_t i;
		for (i = start; i < start + k; i++)
		{
			if (direction == (array[i] > array[i + k]))
			{
				int temp_val = array[i];
				array[i] = array[i + k];
				array[i + k] = temp_val;
			}
		}
		bitonic_merge(array, start, k, direction, temp);
		bitonic_merge(array, start + k, k, direction, temp);
	}
}
