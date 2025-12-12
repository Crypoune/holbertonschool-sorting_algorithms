#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_recursion(array, 0, size - 1, size);
}

/**
 * quick_recursion - Recursively sorts sub-arrays
 * @array: The array to be sorted
 * @low: The starting index of the sub-array
 * @high: The ending index of the sub-array
 * @size: The size of the array
 * Return: void
 */
void quick_recursion(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		quick_recursion(array, low, pivot_index - 1, size);
		quick_recursion(array, pivot_index + 1, high, size);
	}
}

/**
 * partition - Partitions the array around a pivot
 * @array: The array to be partitioned
 * @low: The starting index of the sub-array
 * @high: The ending index of the sub-array
 * @size: The size of the array
 * Return: The index of the pivot after partitioning
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high)
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i);
}
