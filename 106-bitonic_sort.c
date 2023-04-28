#include "sort.h"

void bitonic_sort(int *array, size_t size)
{
	int i, j, k;
	int prod, temp;

	for (k = 2; k <= (int)size; k = k* 2)
	{
		/* Build bitonic sequence */
		for (j = k / 2; j > 0; j = j / 2)
		{
			for (i = 0; i < (int)size; i++)
			{
				prod = i ^ j;
				if (prod > i)
				{
					if (( i & k) == 0 && array[i] > array[prod])
					{
						temp = array[i];
						array[i] = array[prod];
						array[prod] = temp;
					}
					if ((i & k) != 0 && array[i] < array[prod])
					{
						temp = array[i];
						array[i] = array[prod];
						array[prod] = temp;
					}
				}
			}
		}
	}
}


