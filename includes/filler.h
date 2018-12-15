/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 10:02:39 by yochered          #+#    #+#             */
/*   Updated: 2018/12/14 10:02:46 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# define MY_PLAYER "yochered.filler"
# define MAX(x, y) ((x > y) ? x : y)
# define MANHATTAN(x1, x2, y1, y2) ((ABS(x2 - x1)) + ABS((y2 - y1)))
# define X 0
# define Y 1
//Delete
# include <fcntl.h>

typedef struct		s_shape
{
	int				height;
	int				width;
	int				map_w;
	int				map_h;
	int 			**cords;
}					t_shape;

typedef struct		s_desc
{
	char 			m_c;
	char 			e_c;
	int 			b_height;
	int 			b_width;
	char 			**map;
	char 			**piece;
	t_shape			*e;
	t_shape			*p;
}					t_desc;

typedef struct		s_area
{
	int				min_y;
	int 			min_x;
	int 			max_y;
	int 			max_x;
}					t_area;

void				get_description(t_desc *desc);
int 				**fill_map_layout(t_desc *desc);
int					*find_tl_corner(char **map, char c, int height);
int					*nearest_enemy_cell(int x, int y, t_shape *shape);
int					central_cell(char **map, int *cords, char c, t_shape *shape);
void				algorithm(t_desc *desc, int **layout);
int					find_min_x(char **map, char c, int height, int width);
int					find_max_x(char **map, char c, int height, int width);
int					find_max_y(char **map, char c, int height, int width);
#endif
