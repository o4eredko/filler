/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:39:03 by yochered          #+#    #+#             */
/*   Updated: 2018/12/26 18:39:04 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_img	*new_image(t_desc *d)
{
	t_img	*img;

	if (!(img = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	img->img = mlx_new_image(d->mlx, MAP_W, MAP_H);
	img->ptr = mlx_get_data_addr(img->img, &img->bpp, &img->s_l, &img->endian);
	img->bpp /= 8;
	return (img);
}

void	img_putpixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || y < 0 || x > MAP_W || y > MAP_H)
		return ;
	*(int*)(img->ptr + ((x + y * MAP_W) * img->bpp)) = color;
}

void	putsquare(t_img *img, int x, int y, int color)
{
	int w;
	int h;

	w = x * SIZE;
	h = y * SIZE;
	while (y <= h)
	{
		x = w / SIZE - 1;
		while (++x <= w)
			img_putpixel(img, x, y, color);
		y++;
	}
}

void	print_map(t_img *img, t_desc *d, t_frames *frame)
{
	int i;
	int j;

	i = -1;
	while (++i < d->map_h)
	{
		j = -1;
		while (++j < d->map_w)
		{
			if (frame->map[i][j] == '.')
				putsquare(img, j, i, 0xFFFFFF);
		}
	}
	mlx_put_image_to_window(d->mlx, d->win, img->img,(WIDTH - MAP_W) / 2, (HEIGHT - MAP_H) / 2);
}

void	fill_window(t_desc *d, t_frames *head)
{
	t_img	*img;

	img = new_image(d);
	// while (head)
	// {
		print_map(img, d, head);	
		// head = head->next;
	// }	
}