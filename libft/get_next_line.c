/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 10:59:02 by yochered          #+#    #+#             */
/*   Updated: 2018/12/14 10:04:53 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>

static char		*get_line(char *src, t_gnl *gnl, int size)
{
	char	*src_tmp;
	char	*res;
	char	*res_tmp;

	CHECK((res = ft_strnew((size_t)(size + gnl->r_size))));
	res_tmp = res;
	src_tmp = src;
	while (size--)
		*res_tmp++ = *src_tmp++;
	free(src);
	while (gnl->buf[gnl->i] != '\n' && gnl->i < gnl->r_size)
		*res_tmp++ = gnl->buf[gnl->i++];
	return (res);
}

static char		*read_file(char *res, t_gnl *gnl)
{
	while ((gnl->r_size = (int)read(gnl->fd, gnl->buf, BUFF_SIZE)))
	{
		gnl->i = 0;
		CHECK((res = get_line(res, gnl, (int)ft_strlen(res))));
		if (gnl->i < gnl->r_size)
			break ;
	}
	return (res);
}

static t_gnl	*del_create_node(t_gnl *gnl, int fd)
{
	t_gnl	*node;

	if (fd == -1)
	{
		if (gnl->prev)
			gnl->prev->next = gnl->next;
		if (gnl->next)
			gnl->next->prev = gnl->prev;
		free(gnl);
		return (NULL);
	}
	CHECK((node = (t_gnl *)malloc(sizeof(t_gnl))));
	node->fd = fd;
	node->i = 0;
	node->r_size = 0;
	node->next = NULL;
	node->prev = gnl ? gnl : NULL;
	return (node);
}

static t_gnl	*find_fd(t_gnl *search_fd, int fd)
{
	t_gnl	*tmp;
	t_gnl	*cur;

	cur = search_fd;
	while (cur && cur->fd != fd)
	{
		tmp = cur;
		cur = cur->prev;
	}
	while (!cur && search_fd && search_fd->fd != fd)
	{
		tmp = search_fd;
		search_fd = search_fd->next;
	}
	search_fd = cur ? cur : search_fd;
	if (!search_fd)
	{
		CHECK((tmp->next = del_create_node(tmp, fd)));
		return (tmp->next);
	}
	if (read(fd, 0, 0) < 0)
		del_create_node(search_fd, -1);
	return (search_fd);
}

int				get_next_line(const int fd, char **line)
{
	char			*res;
	static t_gnl	*gnl;

	if (!line || fd < 0 || (!gnl && !(gnl = del_create_node(NULL, fd))))
		return (-1);
	if (!(gnl = find_fd(gnl, fd)) || read(gnl->fd, gnl->buf, 0) < 0
		|| !(res = ft_strnew(0)))
		return (-1);
	if (gnl->i < gnl->r_size)
	{
		gnl->i++;
		if (!(res = get_line(res, gnl, 0)))
			return (-1);
	}
	if (gnl->i >= gnl->r_size && !(res = read_file(res, gnl)))
		return (-1);
	if (!gnl->r_size && !(ft_strlen(res)))
	{
		*line = NULL;
		free(res);
		return (0);
	}
	*line = res;
	return (1);
}
