#include "sort.h"

/**
 * merge - Merge two sub-arrays of the array
 *
 * @array: Pointer to the array
 * @left: Pointer to the left sub-array
 * @left_size: Size of the left sub-array
 * @right: Pointer to the right sub-array
 * @right_size: Size of the right sub-array
 **/
void merge(int *array, int *left, size_t left_size, int *right,
	       	size_t right_size)
{
    size_t i = 0, j = 0, k = 0;
    int *tmp = malloc(sizeof(int) * (left_size + right_size));

    if (!tmp)
        return;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
            tmp[k++] = left[i++];
        else
            tmp[k++] = right[j++];
    }

    while (i < left_size)
        tmp[k++] = left[i++];

    while (j < right_size)
        tmp[k++] = right[j++];

    for (i = 0; i < left_size + right_size; i++)
        array[i] = tmp[i];

    printf("[Done]: ");
    print_array(array, left_size + right_size);

    free(tmp);
}

/**
 * merge_sort - Sort an array of integers in ascending order using the 
 * 		Merge sort algorithm
 *
 * @array: Pointer to the array
 * @size: Size of the array
 **/
void merge_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    size_t mid = size / 2, i;
    int *left = array, *right = array + mid;

    merge_sort(left, mid);
    merge_sort(right, size - mid);

    merge(array, left, mid, right, size - mid);
}

