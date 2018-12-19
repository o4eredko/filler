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
# define CHAR(x, c) ((x) == (c) || (x) == (c + 32) ? 1 : 0)
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
	int 			*shift;
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
	int				min_x;
	int 			min_y;
	int 			max_x;
	int 			max_y;
	t_shape			*e;
	t_shape			*p;
}					t_desc;

void				get_player_info(t_desc *desc);
int					get_shape(t_desc *desc);
int					get_map(t_desc *desc);
int					get_size(t_desc *desc);
int 				**fill_map_layout(t_desc *desc);
int					*find_tl_corner(char **map, char c, int height);
int					*nearest_enemy_cell(int x, int y, t_shape *shape);
int					central_cell(char **map, t_shape *shape, char c, int *cords);
void				check_range(t_desc *desc, int x, int y);
void				algorithm(t_desc *desc, int **layout);

void	print_cords(int **cords);
#endif
