/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:03:37 by yochered          #+#    #+#             */
/*   Updated: 2018/10/24 18:03:38 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	i;

	res = (char *)malloc((size + 1) * sizeof(char));
	i = 0;
	if (!res)
		return (NULL);
	while (i < size)
		res[i++] = '\0';
	res[i] = '\0';
	return (res);
}
