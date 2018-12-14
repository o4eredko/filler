/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 09:57:18 by yochered          #+#    #+#             */
/*   Updated: 2018/10/29 09:57:20 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;
	void	*data;
	size_t	size;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	data = (void *)content;
	size = content_size;
	if (!content)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	else
	{
		if (!(node->content = malloc(ft_strlen((char *)content))))
			return (NULL);
		node->content = ft_memcpy(node->content, data, size);
		node->content_size = size;
	}
	node->next = NULL;
	return (node);
}
