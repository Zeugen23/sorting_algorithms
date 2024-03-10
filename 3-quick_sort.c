#include "sort.h"

/**
 * quick_sort - sorts an array with the Quicksort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_recursion(array, 0, (int)size - 1, size);
}

/**
 * quick_recursion - helper function for Quicksort
 * @array: array to sort
 * @left: index of the left element
 * @right: index of the right element
 * @size: size of the array
 */
void quick_recursion(int *array, int left, int right, size_t size)
{
	int piv;

	if (left < right)
	{
		piv = lomuto_partition(array, left, right, size);
		quick_recursion(array, left, piv - 1, size);
		quick_recursion(array, piv + 1, right, size);
	}
}

/**
 * lomuto_partition - performs Lomuto partition scheme for Quicksort
 * @array: array to partition
 * @left: index of the left element
 * @right: index of the right element
 * @size: size of the array
 *
 * Return: the index of the pivot element
 */
int lomuto_partition(int *array, int left, int right, size_t size)
{
	int pivot = array[right];
	int i = left - 1;
	int j, temp;

	for (j = left; j <= right - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[right] != array[i + 1])
	{
		temp = array[i + 1];
		array[i + 1] = array[right];
		array[right] = temp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * print_array - prints an array of integers
 * @array: array to print
 * @size: size of the array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}

	printf("\n");
}
