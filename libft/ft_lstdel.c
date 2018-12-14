/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 11:04:10 by yochered          #+#    #+#             */
/*   Updated: 2018/10/29 11:04:12 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;
	t_list	*next_node;

	if (!alst || !del)
		return ;
	node = *alst;
	while (node)
	{
		next_node = node->next;
		ft_lstdelone(&node, del);
		*alst = (*alst)->next;
		node = next_node;
	}
	*alst = NULL;
}
