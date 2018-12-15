/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:38:29 by yochered          #+#    #+#             */
/*   Updated: 2018/12/15 15:38:30 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		find_min_x(char **map, char c, int height, int width)
{
	int		min_x;
	int		i;
	int		j;

	i = -1;
	min_x = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			if ((min_x == -1 || min_x > j) && (map[i][j] == c || (map[i][j] == c + 32)))
				min_x = j;
	}
	return (min_x);
}

int		find_max_x(char **map, char c, int height, int width)
{
	int		max_x;
	int		i;
	int		j;

	i = -1;
	max_x = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			if ((max_x == -1 || max_x < j) && (map[i][j] == c || (map[i][j] == c + 32)))
				max_x = j;
	}
	return (max_x);
}

int		find_max_y(char **map, char c, int height, int width)
{
	int		max_y;
	int		i;
	int		j;

	i = -1;
	max_y = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			if ((max_y == -1 || max_y < i) && (map[i][j] == c || (map[i][j] == c + 32)))
				max_y = i;
	}
	return (max_y);
}
