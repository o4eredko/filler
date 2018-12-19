/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:02:56 by yochered          #+#    #+#             */
/*   Updated: 2018/12/18 17:02:57 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_VISUALIZE_H
# define FILLER_VISUALIZE_H
# include <curses.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <wchar.h>
# include "../libft/includes/libft.h"
# define CHAR(x, c) ((x) == (c) || (x) == (c + 32) ? 1 : 0)
# define TIME 400000

typedef struct 			s_step
{
	int 				w;
	int 				h;
	char				**map;
}						t_step;

typedef struct 			s_step_list
{
	unsigned int		more : 1;
	t_step				*step;
	struct s_step_list	*next;
	struct s_step_list	*prev;
}						t_step_list;

int						setup_screen(void);
int						setup_colors(void);
t_step_list				*add_node(t_step_list *head, t_step *step);
t_step					*next_step(int fd);
void					print_color(char c, int color_pair);

#endif
