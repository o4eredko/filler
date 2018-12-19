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

#include <filler.h>

void	get_player_info(t_desc *desc)
{
	char	*line;

	if (get_next_line(0, &line) == 1)
	{
		desc->m_c = (char)(line[10] == '1' ? 'O' : 'X');
		desc->e_c = (char)(desc->m_c == 'O' ? 'X' : 'O');
		free(line);
	}
}

int		get_size(t_desc *desc)
{
	char	*line;

	if (get_next_line(0, &line) != 1)
		return (0);
	if (!desc->b_height && !desc->b_width && ft_strnequ(line, "Plateau", 7))
	{
		desc->b_height = ft_atoi(line + 8);
		desc->b_width = ft_atoi(line + 8 + ft_count_digits(desc->b_height, 10));
	}
	else if (!desc->p->map_h && !desc->p->map_w && ft_strnequ(line, "Piece", 5))
	{
		desc->p->map_h = ft_atoi(line + 6);
		desc->p->map_w = ft_atoi(line + 6 +
			ft_count_digits(desc->p->map_h, 10));
	}
	free(line);
	return (1);
}

int		get_map(t_desc *desc)
{
	int		i;

	i = -1;
	if (!(get_size(desc)))
		return (0);
	desc->map = (char**)(malloc(sizeof(char*) * desc->b_height));
	get_next_line(0, &(desc->map[0]));
	free(desc->map[0]);
	while (++i < desc->b_height)
	{
		get_next_line(0, &(desc->map[i]));
		desc->map[i] += 4;
	}
	desc->e->map_h = desc->b_height;
	desc->e->map_w = desc->b_width;
	return (1);
}

int		get_shape(t_desc *desc)
{
	int		i;
	int		*tl;

	i = -1;
	if (!(get_size(desc)))
		return (0);
	desc->piece = (char**)(malloc(sizeof(char*) * desc->p->map_h));
	while (++i < desc->p->map_h)
		get_next_line(0, &(desc->piece[i]));
	tl = find_tl_corner(desc->piece, '*', desc->p->map_h);
	desc->p->shift = tl;
	return (1);
}
