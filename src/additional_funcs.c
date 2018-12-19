/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:00:08 by yochered          #+#    #+#             */
/*   Updated: 2018/12/15 15:00:09 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	check_range(t_desc *desc, int x, int y)
{
	if (CHAR(desc->map[y][x], desc->m_c))
	{
		if (desc->min_x == -1 || desc->min_x > x)
			desc->min_x = x;
		if (desc->max_x == -1 || desc->max_x < x)
			desc->max_x = x;
		if (desc->min_y == -1 || desc->min_y > y)
			desc->min_y = y;
		if (desc->max_y == -1 || desc->max_y < y)
			desc->max_y = y;
	}
}

int		*find_tl_corner(char **map, char c, int height)
{
	int		*cords;
	int		i;
	int		j;

	cords = (int*)ft_memalloc(sizeof(int) * 2);
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (map[i][++j])
			if (CHAR(map[i][j], c))
			{
				cords[X] = j;
				cords[Y] = i;
				return (cords);
			}
	}
	return (cords);
}

int		*nearest_enemy_cell(int x, int y, t_shape *shape)
{
	int		i;
	int		*cords;
	int		distance;

	i = -1;
	cords = (int*)ft_memalloc(sizeof(int) * 2);
	distance = 0;
	while (shape->cords[++i])
	{
		if (MANHATTAN(shape->cords[i][X], x, shape->cords[i][Y], y) < distance
			|| !distance)
		{
			distance = MANHATTAN(shape->cords[i][X], x, shape->cords[i][Y], y);
			cords[X] = shape->cords[i][X];
			cords[Y] = shape->cords[i][Y];
		}
	}
	return (cords);
}

int		central_cell(char **map, t_shape *shape, char c, int *cords)
{
	if (cords[Y] && ((cords[X] && !CHAR(map[cords[Y] - 1][cords[X] - 1], c)) ||
		(!CHAR(map[cords[Y] - 1][cords[X]], c) ||
		(cords[X] < shape->map_w - 1 &&
		!CHAR(map[cords[Y] - 1][cords[X] + 1], c)))))
		return (0);
	if ((cords[X] && !CHAR(map[cords[Y]][cords[X] - 1], c)) ||
		(cords[X] < shape->map_w - 1 &&
		!CHAR(map[cords[Y]][cords[X] + 1], c)))
		return (0);
	if (cords[Y] < shape->map_h - 1 &&
		((cords[X] && !CHAR(map[cords[Y] + 1][cords[X] - 1], c)) ||
		!CHAR(map[cords[Y] + 1][cords[X]], c) ||
		(cords[X] < shape->map_w - 1 &&
		!CHAR(map[cords[Y] + 1][cords[X] + 1], c))))
		return (0);
	return (1);
}
