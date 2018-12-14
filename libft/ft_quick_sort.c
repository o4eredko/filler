/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:01:25 by yochered          #+#    #+#             */
/*   Updated: 2018/10/30 15:01:26 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *tab, int low, int high)
{
	int pivot;
	int i;
	int j;

	pivot = tab[high];
	j = low;
	i = low - 1;
	while (j <= high - 1)
	{
		if (tab[j] <= pivot)
		{
			i++;
			ft_swap(&tab[i], &tab[j]);
		}
		j++;
	}
	ft_swap(&tab[i + 1], &tab[high]);
	return (i + 1);
}

void		ft_quick_sort(int **tab, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(*tab, low, high);
		ft_quick_sort(tab, low, pivot - 1);
		ft_quick_sort(tab, pivot + 1, high);
	}
}
