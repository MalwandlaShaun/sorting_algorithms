#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list
 *
 * @n: integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: pointer to the next element of the list
 * Doubly linked list structure
 *
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* printing helper functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* sorting algorithm */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void merge_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);

void bitonic_sort_helper(int *array, size_t size, size_t count,
		int direction, int *temp);
void bitonic_merge(int *array, size_t start, size_t count,
		int direction, int *temp);

#endif
