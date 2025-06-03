/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:11:48 by diade-so          #+#    #+#             */
/*   Updated: 2025/05/02 17:13:25 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	insertion_sort(int *arr, int left, int right)
{
	int	i;
	int	j;
	int	key;

	if (!arr || left >= right)
		return ;
	i = left + 1;
	while (i <= right)
	{
		key = arr[i];
		j = i - 1;
		while (j >= left && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

int	median_of_three(int *arr, int left, int right)
{
	int	mid;
	int	a;
	int	b;
	int	c;

	mid = (left + right) / 2;
	a = arr[left];
	b = arr[mid];
	c = arr[right];
	if ((a > b && a < c) || (a < b && a > c))
		return (left);
	else if ((b > a && b < c) || (b < a && b > c))
		return (mid);
	else
		return (right);
}

int	partition(int *arr, int left, int right)
{
	int	i;
	int	pivot;
	int	pivot_index;
	int	boundary;

	pivot_index = median_of_three(arr, left, right);
	ft_swap(&arr[pivot_index], &arr[right]);
	pivot = arr[right];
	i = left;
	boundary = i - 1;
	while (i < right)
	{
		if (arr[i] < pivot)
		{
			boundary++;
			ft_swap(&arr[i], &arr[boundary]);
		}
		i++;
	}
	ft_swap(&arr[boundary + 1], &arr[right]);
	return (boundary + 1);
}

void	qsort_hybrid(int *arr, int left, int right)
{
	int	num_elements;
	int	pivot_idx;

	num_elements = right - left + 1;
	if (num_elements <= 16)
	{
		insertion_sort(arr, left, right);
		return ;
	}
	if (left < right)
	{
		pivot_idx = partition(arr, left, right);
		qsort_hybrid(arr, left, pivot_idx - 1);
		qsort_hybrid(arr, pivot_idx + 1, right);
	}
}
