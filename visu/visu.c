/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:36:48 by yochered          #+#    #+#             */
/*   Updated: 2018/12/26 16:36:49 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	put_error(char *str)
{
	if (str)
		ft_printf(RED("%s\n"), str);
	else
		perror(RED("Error"));
	exit(1);
}

void	init_description(t_desc *d)
{
	d->map_h = 0;
	d->map_w = 0;
}

int		main(int ac, char **av)
{
	int			fd;
	t_desc		d;
	t_frames	*head;

	init_description(&d);
	if (ac != 2)
		ft_printf(CYAN("usage: ./visu_filler game_file\n"));
	else
	{
		if ((fd = open(av[1], 0)) == -1)
			put_error(NULL);
		create_window(&d);
		head = parse_file(&d, fd);
		fill_window(&d, head);
		// while (head)
		// {
		// 	for(int i = 0; i < d.map_h; i++)
		// 		ft_printf(CYAN("%s\n"), head->map[i]);
		// 	ft_printf("\n\n");
		// 	head = head->next;
		// }
		mlx_hook(d.win, 2, 5, key_hook, &d);
		mlx_loop(d.mlx);
		if ((close(fd) == -1))
			put_error(NULL);
	}
	return (0);
}