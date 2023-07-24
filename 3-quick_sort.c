#include "sort.h"
void quick_sort_helper(int *array, int low, int high);
int partition(int *array, int low, int high);

/**
 * quick_sort - Sort an array of integers in ascending order
 * @array: Pointer to the array
 * @size: Size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1);
}

/**
 * quick_sort_helper - Recursive function to perform quick sort on the array
 * @array: Pointer to the array
 * @low: Starting index
 * @high: Ending index
 */

void quick_sort_helper(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(array, low, high);

		quick_sort_helper(array, low, pivot - 1);
		quick_sort_helper(array, pivot + 1, high);
	}
}

/**
 * partition - Partition for quck sort
 * @array: Pointer to the array
 * @low: Starting index
 * @high: Ending index
 * Return: Index of the pivot element
 */

int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j < high; ++j)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, high + 1);
			}
		}
	}

	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, high + 1);
	}

	return (i + 1);
}
