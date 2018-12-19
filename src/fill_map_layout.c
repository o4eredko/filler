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

#include <filler.h>

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
			if (CHAR(desc->map[y][x], desc->e_c))
				layout[y][x] = 0;
			else if (CHAR(desc->map[y][x], desc->m_c))
			{
				check_range(desc, x, y);
				layout[y][x] = -1;
			}
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
	int		cords_tmp[2];
	int		size;

	cords_tmp[Y] = cords[Y] - 1;
	size = 0;
	while (++cords_tmp[Y] < shape->map_h)
	{
		cords_tmp[X] = -1;
		while (++cords_tmp[X] < shape->map_w)
			if (CHAR(map[cords_tmp[Y]][cords_tmp[X]], c) &&
			(c == '*' || !central_cell(map, shape, c, cords_tmp)))
			{
				shape->width = (cords_tmp[X] - cords[X] + 1 > shape->width)
						? cords_tmp[X] - cords[X] + 1 : shape->width;
				size++;
			}
		shape->height = (cords_tmp[Y] - cords[Y] + 1 > shape->height)
				? cords_tmp[Y] - cords[Y] + 1 : shape->height;
	}
	return (size);
}

void	fill_shape_cords(char c, char **map, int *cords, t_shape *shape)
{
	int		cords_tmp[2];
	int		k;

	cords_tmp[Y] = cords[Y] - 1;
	k = 0;
	while (++cords_tmp[Y] < cords[Y] + shape->height
		&& cords_tmp[Y] < shape->map_h)
	{
		cords_tmp[X] = -1;
		while (++cords_tmp[X] < cords[X] + shape->width
			&& cords_tmp[X] < shape->map_w)
		{
			if (CHAR(map[cords_tmp[Y]][cords_tmp[X]], c) &&
				(c == '*' || !central_cell(map, shape, c, cords_tmp)))
			{
				shape->cords[k] = (int*)ft_memalloc(2);
				shape->cords[k][X] = cords_tmp[X];
				shape->cords[k++][Y] = cords_tmp[Y];
			}
		}
		shape->cords[k] = NULL;
	}
}

int		**fill_map_layout(t_desc *desc)
{
	int		**layout;
	int		*cords;

	cords = find_tl_corner(desc->map, desc->e_c, desc->b_height);
	desc->e->cords = (int**)ft_memalloc(sizeof(int*) *
			(get_shape_size(desc->e_c, desc->map, cords, desc->e) + 1));
	fill_shape_cords(desc->e_c, desc->map, cords, desc->e);
	layout = create_layout(desc);
	fill_digits(layout, desc);
	free(cords);
	cords = find_tl_corner(desc->piece, '*', desc->p->map_h);
	desc->p->cords = (int**)ft_memalloc(sizeof(int*) *
			(get_shape_size('*', desc->piece, cords, desc->p) + 1));
	fill_shape_cords('*', desc->piece, cords, desc->p);
	free(cords);
	return (layout);
}
