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

#include "../includes/filler.h"

int		*find_tl_corner(char **map, char c, int height)
{
	int		*cords;
	int		i;
	int		j;

	cords = (int*)ft_memalloc(sizeof(int) * 2);
	i = 0;
	j = 0;
	while (i < height && !ft_strchr(map[i], c) && !ft_strchr(map[i], c + 32))
		i++;
	while (map[i][j] && map[i][j] != c && map[i][j] != c + 32)
		j++;
	cords[X] = j;
	cords[Y] = i;
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

int		central_cell(char **map, int *cords, char c, t_shape *shape)
{
	if (cords[Y] && ((j && (map[cords[Y] - 1][j - 1] != c && map[cords[Y] - 1][j - 1] != c - 32))
		|| (map[cords[Y] - 1][j] != c && map[cords[Y] - 1][j] != c - 32) ||
		(cords[X] != shape->map_w - 1 && (map[cords[Y] - 1][cords[X] + 1] != c && map[cords[Y] - 1][cords[X] + 1] != c - 32))))
		return (0);
	if ((j && (map[cords[Y]][cords[X] - 1] != c && map[cords[Y]][cords[X] - 1] != c - 32))
		|| (cords[X] != shape->map_h - 1 && map[cords[Y]][cords[X] + 1] != c && map[cords[Y]][cords[X] + 1] != c - 32))
		return (0);
	if (cords[Y] != shape->map_h
		&& ((cords[X] && map[cords[Y] + 1][cords[X] - 1] != c && map[cords[Y] + 1][cords[X] - 1] != c - 32)
		|| (map[cords[Y] + 1][cords[X]] != c && map[cords[Y] + 1][cords[X]] != c - 32) ||
		(cords[X] < shape->map_w - 1 && map[cords[Y] + 1][cords[X] + 1] != c && map[cords[Y] + 1][cords[X] + 1] != c - 32)))
		return (0);
	return (1);
}
