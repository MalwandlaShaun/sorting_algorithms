#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order using the
 *              LSD radix sort algorithm
 *
 * @array: the array of integers to sort
 * @size: the size of the array
 */
void radix_sort(int *array, size_t size)
{
    int *count = NULL, *bucket = NULL;
    int max_digit = 0, i = 0, j = 0, k = 0, div = 1;

    if (array == NULL || size < 2)
        return;

    max_digit = array[0];
    for (i = 1; i < (int)size; i++)
    {
        if (array[i] > max_digit)
            max_digit = array[i];
    }

    count = malloc(sizeof(int) * 10);
    if (count == NULL)
        return;
    bucket = malloc(sizeof(int) * size);
    if (bucket == NULL)
    {
        free(count);
        return;
    }

    while (max_digit / div > 0)
    {
        for (i = 0; i < 10; i++)
            count[i] = 0;

        for (i = 0; i < (int)size; i++)
            count[(array[i] / div) % 10]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = (int)size - 1; i >= 0; i--)
        {
            j = (array[i] / div) % 10;
            bucket[count[j] - 1] = array[i];
            count[j]--;
        }

        for (i = 0; i < (int)size; i++)
            array[i] = bucket[i];

        print_array(array, size);

        div *= 10;
    }
    free(count);
    free(bucket);
}

