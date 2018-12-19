/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:07:14 by yochered          #+#    #+#             */
/*   Updated: 2018/12/18 14:07:15 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

t_desc	*create_node(t_shape *e, t_shape *p)
{
	t_desc *desc;

	if (!(desc = (t_desc*)malloc(sizeof(t_desc))))
		return (NULL);
	ft_bzero(desc, sizeof(t_desc));
	desc->e = e;
	desc->p = p;
	desc->p->map_h = 0;
	desc->p->map_w = 0;
	ft_bzero(desc->e, sizeof(t_shape));
	ft_bzero(desc->p, sizeof(t_shape));
	desc->min_y = -1;
	desc->min_x = -1;
	desc->max_y = -1;
	desc->max_x = -1;
	return (desc);
}

void	free_memory(t_desc *desc, int **layout)
{
	int i;

	i = -1;
	while (++i < desc->b_height)
	{
		free(desc->map[i] - 4);
		free(layout[i]);
	}
	i = -1;
	while (++i < desc->p->map_h)
		free(desc->piece[i]);
	i = -1;
	while (desc->e->cords[++i])
		free(desc->e->cords[i]);
	i = -1;
	while (desc->p->cords[++i])
		free(desc->p->cords[i]);
	free(desc->e->cords);
	free(desc->p->cords);
	free(desc->p->shift);
	ft_bzero(desc->e, sizeof(t_shape));
	ft_bzero(desc->p, sizeof(t_shape));
	free(layout);
	free(desc->map);
	free(desc->piece);
}

int		main(void)
{
	t_desc	*desc;
	t_shape e;
	t_shape	p;
	int		**layout;

	desc = create_node(&e, &p);
	get_player_info(desc);
	while (get_map(desc) && get_shape(desc))
	{
		layout = fill_map_layout(desc);
		algorithm(desc, layout);
		free_memory(desc, layout);
	}
	free(desc);
	return (0);
}
