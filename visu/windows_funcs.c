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

void	print_players(t_desc *d)
{
	mlx_string_put(d->mlx, d->win, WIDTH / 2 - 200, 50, d->my_col, "yochered.filler");
	mlx_string_put(d->mlx, d->win, WIDTH / 2 - 10, 50, 0xffffff, "VS");
	mlx_string_put(d->mlx, d->win, WIDTH / 2 + 50, 50, d->enem_col, d->enemy);
}

void	update_scale(t_desc *d, t_img *img)
{
	int tmp1;
	int tmp2;
	int	border;
	int i;

	border = ((double)img->width / 100) * (double)(g_my_score / ((double)(g_my_score + g_e_score) / 100));
	i = -1;
	while (++i < img->height)
	{
		tmp1 = -1;
		tmp2 = img->width;
		while (++tmp1 <= border)
			img_putpixel(img, tmp1, i, d->my_col);
		while (--tmp2 >= border)
			img_putpixel(img, tmp2, i, d->enem_col);
	}
	mlx_put_image_to_window(d->mlx, d->win, img->img, (WIDTH - img->width) / 2, HEIGHT - 100);
}

t_img	*create_scale(t_desc *d)
{
	t_img	*img;

	if (!(img = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	img->height = 15;
	img->width = 400;
	img->img = mlx_new_image(d->mlx, img->width, img->height);
	img->ptr = mlx_get_data_addr(img->img, &img->bpp, &img->s_l, &img->endian);
	img->bpp /= 8;
	return (img);
}

void	print_score(t_desc *d)
{
	char *res;

	if (d->e_score > d->my_score)
	{
		res = ft_strjoin("WINNER: ", d->enemy);
		mlx_string_put(d->mlx, d->win, WIDTH / 2 - ft_strlen(res) * 5, HEIGHT - 60, d->enem_col, res);
		free(res);
	}
	else
	{
		res = ft_strjoin("WINNER: ", "yochered.filler");
		mlx_string_put(d->mlx, d->win, WIDTH / 2 - ft_strlen(res) * 5, HEIGHT - 60, d->my_col, res);
		free(res);
	}
}

void	create_window(t_desc *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "FILLER");
	print_players(d);
	d->scale = create_scale(d);
}

int		key_hook(int key, void *param)
{
	t_desc	*desc;

	desc = (t_desc*)param;
	while (key == 49 && fill_window(desc, desc->head, 1))
	{
		mlx_do_sync(desc->mlx);
		update_scale(desc, desc->scale);
	}
	if (key == 53)
	{
		mlx_destroy_window(desc->mlx, desc->win);
		exit(0);
	}
	if (key == 123 || key == 124)
	{
		fill_window(desc, desc->head, key == 123 ? -1 : 1);
		update_scale(desc, desc->scale);
	}
	return (0);
}
