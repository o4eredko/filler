/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:08:08 by yochered          #+#    #+#             */
/*   Updated: 2018/10/30 18:13:56 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!s1 || !s2 || !n)
		return (1);
	while (n > 0)
	{
		if (!s1[i] && !s2[i])
			return (1);
		if (s1[i] != s2[i])
			return (0);
		n--;
		i++;
	}
	return (1);
}
