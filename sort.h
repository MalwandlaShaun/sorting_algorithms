#ifndef SORT_H
#define SORT_H

/*print_list and print_array functions*/

/**
 * print_array - Prints an array of integers
 * print_list - Prints a list of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 * @list: The list to be printed
 */

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/**
 * bubble_sort - sorts an array of integers in ascending order
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */

void bubble_sort(int *array, size_t size);

#endif
