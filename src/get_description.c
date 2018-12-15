/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_description.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 10:02:34 by yochered          #+#    #+#             */
/*   Updated: 2018/12/14 10:02:35 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_player_info(t_desc *desc)
{
	int 	i;
	char	*line;

	i = 0;
	while (++i <= 2)
	{
		get_next_line(1, &line);
		if (ft_strstr(line, MY_PLAYER))
			desc->m_c = (char)(i == 1 ? 'O' : 'X');
	}
	desc->e_c = (char)(desc->m_c == 'X' ? 'O' : 'X');
}

void	get_size(t_desc *desc)
{
	char	*line;
	get_next_line(1, &line);
	if (ft_strstr(line, "Plateau"))
	{
		desc->b_height = ft_atoi(line + 8);
		desc->b_width = ft_atoi(line + 8 + ft_count_digits(desc->b_height, 10));
	}
	else if (ft_strstr(line, "Piece"))
	{
		desc->p->map_h = ft_atoi(line + 6);
		desc->p->map_w = ft_atoi(line + 6 + ft_count_digits(desc->p->map_h, 10));
	}
}

void	get_map(t_desc *desc)
{
	char	*tmp;
	int		i;

	i = -1;
	desc->map = (char**)(malloc(sizeof(char*) * desc->b_height));
	get_next_line(1, &tmp);
	while (++i < desc->b_height)
		get_next_line(1, &(desc->map[i]));
	while (i--)
	{
		tmp = ft_strsub(desc->map[i], 4, ft_strlen(desc->map[i]));
		free(desc->map[i]);
		desc->map[i] = tmp;
	}
	desc->e->map_h = desc->b_height;
	desc->e->map_w = desc->b_width;
}

void	get_piece(t_desc *desc)
{
	int		i;

	i = -1;
	desc->piece = (char**)(malloc(sizeof(char*) * desc->p->map_h));
	while (++i < desc->p->map_h)
		get_next_line(1, &(desc->piece[i]));
	desc->p->map_h = desc->p->map_h;
	desc->p->map_w = desc->p->map_w;
}

void	get_description(t_desc *desc)
{
	get_player_info(desc);
	get_size(desc);
	get_map(desc);
	get_size(desc);
	get_piece(desc);
}
