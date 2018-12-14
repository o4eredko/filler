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

int		*nearest_enemy_cell(t_enemy *e, int x, int y)
{
	int 	i;
	int 	*cords;
	int 	distance;

	i = -1;
	cords = (int*)ft_memalloc(sizeof(int) * 2);
	distance = 0;
	while (e->cords[++i])
	{
		if (MANHATTAN(e->cords[i][X], x, e->cords[i][Y], y) < distance || !distance)
		{
			distance = MANHATTAN(e->cords[i][X], x, e->cords[i][Y], y);
			cords[X] = e->cords[i][X];
			cords[Y] = e->cords[i][Y];
		}
	}
	return (cords);
}

void	fill_digits(int **layout, t_desc *desc, t_enemy *e)
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
			if (desc->map[y][x] == desc->e)
				layout[y][x] = 0;
			else if (desc->map[y][x] == desc->p)
				layout[y][x] = -1;
			else
			{
				cords = nearest_enemy_cell(e, x, y);
				layout[y][x] = MAX(ABS(x - cords[X]), ABS(y - cords[Y]));
				free(cords);
			}
		}
	}
}

int 	central_cell(t_desc *desc, t_enemy *e, int i, int j)
{
	if (i && ((j && desc->map[i - 1][j - 1] != desc->e) || desc->map[i - 1][j] != desc->e
	|| (j != desc->b_width - 1 && desc->map[i - 1][j + 1] != desc->e)))
		return (0);
	if ((j && desc->map[i][j - 1] != desc->e) || (j != desc->b_width - 1 && desc->map[i][j + 1] != desc->e))
		return (0);
	if (i != desc->b_height && ((j && desc->map[i + 1][j - 1] != desc->e) || desc->map[i + 1][j] != desc->e
	|| (j < desc->b_width - 1 && desc->map[i + 1][j + 1] != desc->e)))
		return (0);
	return (1);
}

int		get_shape_size(t_desc *desc, t_enemy *e, int i, int j)
{
	int size;
	int y;
	int x;

	y = i;
	x = j;
	e->height = 0;
	e->width = 0;
	size = 0;
	while (i < desc->b_height && strchr(desc->map[i], desc->e))
	{
		j = x - 1;
		while (++j < desc->b_width)
		{
			if (desc->map[i][j] == desc->e && !central_cell(desc, e, i, j))
			{
				if (j - x + 1 > e->width)
					e->width = j - x + 1;
				size++;
			}
		}
		if (i - y + 1 > e->height)
			e->height = i - y + 1;
		i++;
	}
	return (size);
}

void	fill_cords(t_desc *desc, t_enemy *e, int i, int j)
{
	int i_tmp;
	int j_tmp;
	int k;

	i_tmp = i;
	j_tmp = j;
	k = 0;
	while (i < i_tmp + e->height)
	{
		j = j_tmp - 1;
		while (++j < j_tmp + e->width)
		{
			if (desc->map[i][j] == desc->e && !central_cell(desc, e, i, j))
			{
				e->cords[k] = (int*)ft_memalloc(2);
				e->cords[k][X] = j;
				e->cords[k++][Y] = i;
			}
		}
		i++;
	}
}

int 	**fill_map_layout(t_desc *desc)
{
	t_enemy	e;
	int		**layout;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < desc->b_height && !ft_strchr(desc->map[i], desc->e))
		i++;
	while (desc->map[i][j] && desc->map[i][j] != desc->e)
		j++;
	e.cords = (int**)ft_memalloc(sizeof(int*) * (get_shape_size(desc, &e, i, j) + 1));
	fill_cords(desc, &e, i, j);
	for (int k = 0; e.cords[k]; k++)
		printf("(%d, %d)\n", e.cords[k][X], e.cords[k][Y]);
	layout = create_layout(desc);
	fill_digits(layout, desc, &e);
	return (layout);
}
