/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_layout.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 10:02:19 by yochered          #+#    #+#             */
/*   Updated: 2018/12/14 10:02:21 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		**create_layout(t_desc *desc)
{
	int **layout;
	int i;

	i = -1;
	layout = (int**)malloc(sizeof(int*) * desc->b_height);
	while (++i < desc->b_height)
		layout[i] = (int*)malloc(sizeof(int) * desc->b_width);
	return (layout);
}

void	fill_digits(int **layout, t_desc *desc)
{
	int y;
	int x;
	int *cords;

	y = -1;
	while (++y < desc->b_height)
	{
		x = -1;
		while (++x < desc->b_width)
		{
			if (desc->map[y][x] == desc->e_c)
				layout[y][x] = 0;
			else if (desc->map[y][x] == desc->m_c)
				layout[y][x] = -1;
			else
			{
				cords = nearest_enemy_cell(x, y, desc->e);
				layout[y][x] = MAX(ABS(x - cords[X]), ABS(y - cords[Y]));
				free(cords);
			}
		}
	}
}

int		get_shape_size(char c, char **map, int *cords, t_shape *shape)
{
	int		size;
	int		y;
	int		x;

	y = cords[Y] - 1;
	size = 0;
	while (++y < shape->map_h && ft_strchr(map[y], c))
	{
		x = cords[X] - 1;
		while (++x < shape->map_w)
			if (map[cords[Y]][cords[X]] == c
			&& (c != 'e' || !central_cell(map, cords, c, shape)))
			{
				shape->width = (x - cords[X] + 1 > shape->width)
						? x - cords[X] + 1 : shape->width;
				size++;
			}
		shape->height = (y - cords[Y] + 1 > shape->height)
				? y - cords[Y] + 1 : shape->height;
	}
	return (size);
}

void	fill_shape_cords(char c, char **map, int cords[2], t_shape *shape)
{
	int		i_tmp;
	int		j_tmp;
	int		k;

	i_tmp = cords[Y] - 1;
	k = 0;
	while (++i_tmp < cords[Y] + shape->height)
	{
		j_tmp = -1;
		while (++j_tmp < cords[X] + shape->map_w)
		{
			if (map[i_tmp][j_tmp] == c
			&& (c != 'e' || !central_cell(map, cords, c, shape)))
			{
				shape->cords[k] = (int*)ft_memalloc(2);
				shape->cords[k][X] = j_tmp;
				shape->cords[k++][Y] = i_tmp;
			}
		}
	}
}

int		**fill_map_layout(t_desc *desc)
{
	int		**layout;
	int		*cords;

	desc->e->height = 0;
	desc->e->width = 0;
	cords = find_tl_corner(desc->map, desc->e_c, desc->b_height);
	desc->e->cords = (int**)ft_memalloc(sizeof(int*) *
			(get_shape_size(desc->e_c, desc->map, cords, desc->e) + 1));
	fill_shape_cords(desc->e_c, desc->map, cords, desc->e);
	layout = create_layout(desc);
	fill_digits(layout, desc);
	desc->p->height = 0;
	desc->p->width = 0;
	cords = find_tl_corner(desc->piece, '*', desc->p->map_h);
	desc->p->cords = (int**)ft_memalloc(sizeof(int*) *
			(get_shape_size('*', desc->piece, cords, desc->p) + 1));
	fill_shape_cords('*', desc->piece, cords, desc->p);
	return (layout);
}
