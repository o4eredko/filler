/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:37:15 by yochered          #+#    #+#             */
/*   Updated: 2018/12/14 17:37:17 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		move_cords(int **cords, int x, int y, t_desc *desc)
{
	int i;
	int ret;
	int diff_x;
	int diff_y;

	ret = 1;
	diff_x = x - cords[0][X];
	diff_y = y - cords[0][Y];
	i = -1;
	if (cords[0][X] != x || cords[0][Y] != y)
		while (cords[++i])
		{
			cords[i][X] += diff_x;
			cords[i][Y] += diff_y;
			if (cords[i][X] < 0 || cords[i][Y] < 0 ||
			cords[i][Y] > desc->b_height - 1 || cords[i][X] > desc->b_width - 1
			|| CHAR(desc->map[cords[i][Y]][cords[i][X]], desc->e_c))
				ret = 0;
		}
	return (ret);
}

int		check_sum(int **layout, int **cords)
{
	int i;
	int sum;

	i = -1;
	sum = 0;
	while (cords[++i])
		sum += layout[cords[i][Y]][cords[i][X]];
	return (sum);
}

int		check_adjacent(t_desc *desc, int **cords)
{
	int adjacent;
	int i;

	i = -1;
	adjacent = 0;
	while (cords[++i])
		if (CHAR(desc->map[cords[i][Y]][cords[i][X]], desc->m_c))
			adjacent++;
	return (adjacent == 1);
}

void	shift_piece(t_desc *desc, int *cords, int **layout)
{
	int tmp;
	int sum;

	tmp = desc->min_x;
	sum = -1;
	cords[X] = 0;
	cords[Y] = 0;
	while (desc->min_y <= desc->max_y)
	{
		desc->min_x = tmp;
		while (desc->min_x <= desc->max_x)
		{
			if (move_cords(desc->p->cords, desc->min_x, desc->min_y, desc) &&
			(sum == -1 || check_sum(layout, desc->p->cords) <= sum) &&
			check_adjacent(desc, desc->p->cords))
			{
				sum = check_sum(layout, desc->p->cords);
				cords[X] = desc->min_x;
				cords[Y] = desc->min_y;
			}
			desc->min_x++;
		}
		desc->min_y++;
	}
}

void	algorithm(t_desc *desc, int **layout)
{
	int *cords;

	cords = (int*)ft_memalloc(sizeof(int) * 2);
	desc->min_x -= desc->p->width - 1;
	desc->max_x += desc->p->width - 1;
	desc->min_y -= desc->p->height - 1;
	desc->max_y += desc->p->height - 1;
	desc->min_x = desc->min_x < 0 ? 0 : desc->min_x;
	desc->max_x = desc->max_x > desc->b_width - 1
		? desc->b_width - 1 : desc->max_x;
	desc->min_y = desc->min_y < 0 ? 0 : desc->min_y;
	desc->max_y = desc->max_y > desc->b_height - 1
		? desc->b_height - 1 : desc->max_y;
	shift_piece(desc, cords, layout);
	cords[X] -= desc->p->shift[X];
	cords[Y] -= desc->p->shift[Y];
	ft_printf("%d %d\n", cords[Y], cords[X]);
	free(cords);
}
