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
//Delete
# include <fcntl.h>
# define MAX(x, y) ((x > y) ? x : y)
# define MANHATTAN(x1, x2, y1, y2) ((ABS(x2 - x1)) + ABS((y2 - y1)))
# define X 0
# define Y 1

typedef struct		s_desc
{
	char 			p;
	char 			e;
	int 			b_height;
	int 			b_width;
	int 			p_height;
	int 			p_width;
	char 			**map;
}					t_desc;

typedef struct		s_enemy
{
	int 			**cords;
	int 			width;
	int 			height;
}					t_enemy;

void				get_description(t_desc *desc);
int				 	**fill_map_layout(t_desc *desc);

#endif
