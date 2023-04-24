#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

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
void selection_sort(int *array, size_t size);

#endif
