/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:10:45 by yochered          #+#    #+#             */
/*   Updated: 2018/12/26 18:10:47 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_frames	*create_node(t_frames *prev, t_desc *d, int fd)
{
	int			i;
	t_frames	*node;

	i = -1;
	if (!(node = (t_frames*)malloc(sizeof(t_frames))))
		return (NULL);
	node->prev = prev ? prev : NULL;
	node->next = NULL;
	node->map = (char**)malloc(sizeof(char*) * d->map_h);
	get_next_line(fd, &(node->map[0]));
	free(node->map[0]);
	while (++i < d->map_h)
	{
		get_next_line(fd, &(node->map[i]));
		node->map[i] += 4;
	}
	return (node);
}

void		insert_to_list(t_frames **head, int fd, char *line, t_desc *d)
{
	int 		i;
	t_frames	*frame;

	i = -1;
	if (!d->map_h)
		d->map_h = ft_atoi(line + 8);
	if (!d->map_w)
		d->map_w = ft_atoi(line + ft_count_digits(d->map_h, 10) + 9);
	if (!*head)
		*head = create_node(NULL, d, fd);
	else
	{
		frame = *head;
		while (frame->next)
			frame = frame->next;
		frame->next = create_node(frame, d, fd);
	}
}

t_frames	*parse_file(t_desc *d, int fd)
{
	char		*line;
	t_frames	*head;

	head = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strstr(line, "yochered.filler"))
		{
			d->m_c = *(line + 10) == 1 ? 'O' : 'X';
			d->e_c = d->m_c = 'O' ? 'X' : 'O';
		}
		if (ft_strnequ(line, "Plateau", 7))
			insert_to_list(&head, fd, line, d);
	}
	return (head);
}
