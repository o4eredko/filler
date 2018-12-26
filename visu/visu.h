/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:37:01 by yochered          #+#    #+#             */
/*   Updated: 2018/12/26 16:37:02 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VISU_H
# define VISU_H
# include "mlx.h"
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# define WIDTH 1920
# define HEIGHT 1280
# define MAP_H 1000
# define MAP_W 1000
# define SIZE 30

typedef struct		s_desc
{
	void			*mlx;
	void			*win;
	char			m_c;
	char			e_c;
	int				map_h;
	int				map_w;
}					t_desc;

typedef struct		s_frames
{
	char			**map;
	struct s_frames	*next;
	struct s_frames	*prev;
}					t_frames;

typedef struct 		s_img
{
	void			*img;
	void			*ptr;
	int				bpp;
	int				s_l;
	int				endian;
}					t_img;

t_frames			*parse_file(t_desc *d, int fd);
void				create_window(t_desc *d);
int					key_hook(int key, void *param);
void				fill_window(t_desc *d, t_frames *head);
void				img_putpixel(t_img *img, int x, int y, int color);

#endif
