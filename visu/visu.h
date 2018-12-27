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
# define MIN(x, y) (x) < (y) ? (x) : (y)
# define WIDTH 1920
# define HEIGHT 1280
# define CHAR(x, c) ((x) == (c) || (x) == (c + 32) ? 1 : 0)
# define B_COL 0x2a472a
# define TIME 1000

int					g_my_score;
int					g_e_score;

typedef struct		s_desc
{
	void			*mlx;
	void			*win;
	char			m_c;
	char			e_c;
	int				my_col;
	int				enem_col;
	int				map_h;
	int				map_w;
	char			*enemy;
	int				my_score;
	int				e_score;
	struct s_img	*scale;
	struct s_frames	*head;
	int				i;
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
	int				sq_size;
	int				bpp;
	int				s_l;
	int				endian;
	int				height;
	int				width;
	int				bor;
}					t_img;

t_frames			*parse_file(t_desc *d, int fd);
void				create_window(t_desc *d);
int					key_hook(int key, void *param);
int					fill_window(t_desc *d, t_frames *head, int flag);
void				img_putpixel(t_img *img, int x, int y, int color);
void				print_score(t_desc *d);
t_img				*create_scale(t_desc *d);

#endif
