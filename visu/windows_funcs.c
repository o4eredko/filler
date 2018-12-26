/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:46:41 by yochered          #+#    #+#             */
/*   Updated: 2018/12/26 16:46:42 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	create_window(t_desc *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "FILLER");
}

int		key_hook(int key, void *param)
{
	t_desc	*desc;

	desc = (t_desc*)param;
	if (key == 53)
	{
		mlx_destroy_window(desc->mlx, desc->win);
		exit(0);
	}
	return (0);
}
