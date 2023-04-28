#include "sort.h"

/**
 * shift_down - Move the element at the root of a heap down to its proper position
 * @array: The array representing the heap
 * @start: The index of the root of the heap
 * @end: The index of the last element in the heap
 *
 * Return: void
 */
void shift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child, swap;
	int tmp;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap != root)
		{
			tmp = array[root];
			array[root] = array[swap];
			array[swap] = tmp;
			print_array(array, size);
			root = swap;
		}
		else
			return;
	}
}

/**
 * heap_sort - Sort an array of integers using the heap sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int tmp;

	if (array == NULL || size < 2)
		return;

	/* Convert array to a heap */
	for (end = size / 2; end > 0; end--)
	{
		shift_down(array, end - 1, size - 1, size);
	}


	/* Sort the heap */
	for (end = size - 1; end > 0; end--)
	{
		tmp = array[end];
		array[end] = array[0];
		array[0] = tmp;
		if (end != 1)
			print_array(array, size);
		shift_down(array, 0, end - 1, size);
	}
}
