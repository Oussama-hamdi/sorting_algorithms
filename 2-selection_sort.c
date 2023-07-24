#include "sort.h"

/**
 * selection_sort - Sort an array of integers in ascending order
 * @array: Pointer to the array
 * @size: Size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min_index, temp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; ++i)
	{
		min_index = 1;
		for (j = i + 1; j < size; ++j)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		if (min_index != (int)i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
