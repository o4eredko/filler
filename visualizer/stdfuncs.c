/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdfuncs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:22:37 by yochered          #+#    #+#             */
/*   Updated: 2018/12/19 17:22:37 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualize.h>

int			setup_screen(void)
{
	initscr();
	noecho();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	clear();
	setup_colors();
	refresh();
	usleep(TIME);
	return (1);
}

int			setup_colors(void)
{
	start_color();
	init_color(COLOR_RED, 500, 0, 0);
	init_color(COLOR_GREEN, 0, 500, 0);
	init_pair(1, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_CYAN);
	init_pair(3, COLOR_BLACK, COLOR_RED);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_RED, COLOR_CYAN);
	init_pair(8, COLOR_WHITE, COLOR_RED);
	return (1);
}

void		print_color(char c, int color_pair)
{
	attron(COLOR_PAIR(color_pair));
	printw("%c", c);
	attroff(COLOR_PAIR(color_pair));
}

t_step_list	*add_node(t_step_list *head, t_step *step)
{
	t_step_list *node;
	t_step_list *p;

	p = head;
	if (!step->map)
		head->more = 0;
	if (!p)
	{
		p = (t_step_list*)malloc(sizeof(t_step_list));
		p->next = NULL;
		p->prev = NULL;
		p->step = step;
		p->more = 1;
		return (p);
	}
	while (p->next)
		p = p->next;
	node = (t_step_list*)malloc(sizeof(t_step_list));
	node->next = NULL;
	node->prev = p;
	node->step = step;
	p->next = node;
	return (head);
}

t_step		*next_step(int fd)
{
	t_step	*step;
	char	*line;
	int		i;

	step = (t_step*)ft_memalloc(sizeof(t_step));
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strnequ(line, "Plateau", 7))
		{
			i = -1;
			step->w = ft_atoi(line + 8);
			step->h = ft_atoi(line + ft_count_digits(step->w, 10) + 9);
			step->map = (char**)malloc(sizeof(char*) * (step->w + 1));
			while (++i < step->w)
				get_next_line(fd, &(step->map[i]));
			break ;
		}
		else if (ft_strstr(line, "fin"))
		{
			step->w = ft_atoi(&line[10]);
			get_next_line(fd, &line);
			step->h = ft_atoi(&line[10]);
		}
	}
	return (step);
}
