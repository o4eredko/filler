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
	img->sq_size = MIN((WIDTH - 400) / d->map_w, (HEIGHT - 200) / d->map_h);
	img->height = d->map_h * img->sq_size;
	img->width = d->map_w * img->sq_size;
	img->bor = img->sq_size < 20 ? 1 : 2;
	img->img = mlx_new_image(d->mlx, img->width, img->height);
	img->ptr = mlx_get_data_addr(img->img, &img->bpp, &img->s_l, &img->endian);
	img->bpp /= 8;
	return (img);
}

void	img_putpixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	*(int*)(img->ptr + ((x + y * img->width) * img->bpp)) = color;
}

void	putsquare(t_img *img, int x, int y, int color)
{
	int w;
	int h;

	w = x + img->sq_size;
	h = y + img->sq_size;
	while (y < h)
	{
		x = w - img->sq_size;
		while (x < w)
		{
			if (x < w - img->sq_size + img->bor || x >= w - img->bor
				|| y < h - img->sq_size + img->bor || y >= h - img->bor)
				img_putpixel(img, x, y, B_COL);
			else
				img_putpixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	print_map(t_img *img, t_desc *d, t_frames *frame)
{
	int i;
	int j;

	i = 0;
	while (++i < d->map_h)
	{
		j = -1;
		while (++j < d->map_w)
		{
			if (frame->map[i][j] == '.')
				putsquare(img, j * img->sq_size, i * img->sq_size, 0xecebec);
			else if (CHAR(frame->map[i][j], d->m_c))
				putsquare(img, j * img->sq_size, i * img->sq_size, d->my_col);
			else if (CHAR(frame->map[i][j], d->e_c))
				putsquare(img, j * img->sq_size, i * img->sq_size, d->enem_col);
		}
	}
	mlx_put_image_to_window(d->mlx, d->win, img->img, (WIDTH - img->width) / 2, (HEIGHT - img->height) / 2);
}

int		fill_window(t_desc *d, t_frames *head, int flag)
{
	static t_frames *cur;
	t_img			*img;

	img = new_image(d);
	cur = cur ? cur : head;
	if (!cur)
		return (0);
	if (d->i && g_my_score < d->my_score)
		g_my_score += (flag == 1 ? 1 : -1);
	else if (!d->i && g_e_score < d->e_score)
		g_e_score += (flag == 1 ? 1 : -1);
	d->i += (flag == 1 ? 1 : -1);
	if (cur->prev && flag == -1)
		cur = cur->prev;
	else if (cur->next && flag == 1)
		cur = cur->next;
	print_map(img, d, cur);
	if (!cur->next)
	{
		print_score(d);
		return (0);
	}
	return (1);
}