/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cycle_detector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:47:52 by yochered          #+#    #+#             */
/*   Updated: 2018/10/29 17:47:53 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_cycle_detector(t_list *list)
{
	t_list	*hare;
	t_list	*tortoise;

	if (!list)
		return (1);
	tortoise = list;
	hare = list;
	while (1)
	{
		tortoise = tortoise->next;
		if (hare->next != NULL)
			hare = hare->next->next;
		else
			return (0);
		if (!hare || !tortoise)
			return (0);
		if (hare == tortoise)
			return (1);
	}
}
