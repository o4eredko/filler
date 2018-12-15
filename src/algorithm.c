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

#include "../includes/filler.h"

void	print_cords(int **cords)
{
	int i;

	i = -1;
	while (cords[++i])
		ft_printf("x: %d, y: %d\n", cords[i][X], cords[i][Y]);
}

void	move_cords(int **cords, int x, int y)
{
	int i;

	while (cords[0][X] != x)
	{
		i = -1;
		while (cords[++i])
			cords[i][X] += (x - cords[0][X] < 0) ? -1 : 1;
	}
	while (cords[0][Y] != y)
	{
		i = -1;
		while (cords[++i])
			cords[i][Y] += (y - cords[0][Y] < 0) ? -1 : 1;
	}
}

int 	check_sum(int **layout, int **cords)
{
	int i;
	int sum;

	i = -1;
	sum = 0;
	while (cords[++i])
		sum += layout[cords[i][Y]][cords[i][X]];
	return (sum);
}

int 	check_adjacent(char **map, int **cords)
{
	int adjacent;
	int i;

	i = -1;
	adjacent = 0;
	while (cords[++i])
		if (map[cords[i][Y]][cords[i][X]] != '.')
			adjacent++;
	return (adjacent == 1);
}

void	shift_piece(t_desc *desc, t_area area, int *cords, int **layout)
{
	int tmp;
	int sum;

	tmp = area.min_x;
	sum = -1;
	while (area.min_y <= area.max_y)
	{
		area.min_x = tmp;
		while (area.min_x <= area.max_x)
		{
			move_cords(desc->p->cords, area.min_x, area.min_y);
			if ((sum == -1 || check_sum(layout, desc->p->cords) < sum)
				&& check_adjacent(desc->map, desc->p->cords))
			{
				sum = check_sum(layout, desc->p->cords);
				cords[X] = area.min_x;
				cords[Y] = area.min_y;
			}
			area.min_x++;
		}
		area.min_y++;
	}
}

int 	*find_solution(int *tl, t_desc *desc, int **layout)
{
	int		*cords;
	t_area	area;

	cords = (int*)ft_memalloc(sizeof(int) * 2);
	area.min_y = (tl[Y] - desc->p->height) > 0 ? tl[Y] - desc->p->height + 1 : 0;
	area.max_y = (find_max_y(desc->map, desc->m_c, desc->b_height, desc->b_width)) + desc->p->height - 1;
	area.min_x = (find_min_x(desc->map, desc->m_c, desc->b_height, desc->b_width)) - desc->p->width + 1;
	area.max_x = (find_max_x(desc->map, desc->m_c, desc->b_height, desc->b_width)) + desc->p->width - 1;
	area.min_x = area.min_x < 0 ? 0 : area.min_x;
	area.max_x = desc->b_width - desc->p->width < area.max_x ? desc->b_width - desc->p->width : area.max_x;
	area.max_y = desc->b_height - desc->p->height < area.max_y ? desc->b_height - desc->p->height : area.max_y;
	shift_piece(desc, area, cords, layout);
//	ft_printf("Result: (%d : %d)\n", cords[X], cords[Y]);
	return (cords);
}

void	algorithm(t_desc *desc, int **layout)
{
	int *cords;

	cords = find_tl_corner(desc->map, desc->m_c, desc->b_height);
	cords = find_solution(cords, desc, layout);
	cords[X] -= desc->p->map_w - desc->p->width;
	cords[Y] -= desc->p->map_h - desc->p->height;
	ft_printf("%d %d\n", cords[X], cords[Y]);
}
