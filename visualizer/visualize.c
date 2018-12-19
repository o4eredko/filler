/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:02:48 by yochered          #+#    #+#             */
/*   Updated: 2018/12/19 19:02:49 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualize.h>

int			print_result(t_step_list *node)
{
	int row;
	int col;
	int ch;

	getyx(stdscr, row, col);
	move(row + 1, 0);
	printw("Final Score:\n");
	attron(COLOR_PAIR(7));
	printw("Player 1 Result: %i\n", node->step->w);
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(8));
	printw("Player 2 Result: %i\n", node->step->h);
	attroff(COLOR_PAIR(8));
	refresh();
	while (1)
	{
		nodelay(stdscr, TRUE);
		if ((ch = getch()) == ERR)
			continue ;
		else if (ch == 27)
			break ;
		sleep(TIME / 50);
	}
	return (1);
}

int			print_step(t_step_list *node)
{
	int		i;
	int		j;
	char	*str;

	i = 1;
	if (!node->step->map)
		return (print_result(node));
	move(0, 0);
	printw("Map %i %i:", node->step->w, node->step->h);
	while (++i < node->step->w + 2)
	{
		move(i - 1, 0);
		str = node->step->map[i - 2];
		j = -1;
		while (++j < (int)ft_strlen(str))
		{
			if (CHAR(str[j], 'O') || CHAR(str[j], 'X'))
				print_color(' ', CHAR(str[j], 'O') ? 2 : 3);
			else
				str[j] == '.' ? print_color(' ', 1) : print_color(str[j], 6);
		}
		printw("\n");
	}
	return (1);
}

void		step_mode(t_step_list **p)
{
	int ch;

	usleep(TIME / 50);
	while (1)
	{
		ch = getch();
		if (ch == ' ')
			break ;
		else if (ch == KEY_LEFT)
		{
			if ((*p)->prev)
				*p = (*p)->prev;
			print_step(*p);
			refresh();
			usleep(TIME / 50);
		}
		else if (ch == KEY_RIGHT)
		{
			if ((*p)->next->step->map)
				*p = (*p)->next;
			print_step(*p);
			refresh();
			usleep(TIME / 50);
		}
	}
}

int			play_frames(t_step_list *head)
{
	t_step_list	*p;
	int			speed;
	int			ch;

	speed = 10;
	p = head;
	while (p)
	{
		nodelay(stdscr, TRUE);
		if ((ch = getch()) == ERR)
		{
			print_step(p);
			refresh();
			p = p->next;
			usleep(TIME / speed);
		}
		else if (ch == KEY_DOWN && speed > 1 && speed < 100)
			speed--;
		else if (ch == KEY_UP && speed < 100)
			speed++;
		else if (ch == ' ')
			step_mode(&p);
	}
	usleep(TIME / 50);
	return (1);
}

int			main(int ac, char **av)
{
	t_step_list	*step;
	int			fd;

	step = NULL;
	if (ac == 1)
		return (1);
	fd = open(av[1], O_RDONLY);
	setup_screen();
	while (1)
		if ((step = add_node(step, next_step(fd))) && !step->more)
			break ;
	play_frames(step);
	clear();
	refresh();
	endwin();
	close(fd);
	return (0);
}

