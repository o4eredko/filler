/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 10:53:14 by yochered          #+#    #+#             */
/*   Updated: 2018/10/27 10:53:25 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	char *str;
	char *last_s;

	last_s = NULL;
	str = (char *)s;
	if ((char)c == '\0')
		return (str + ft_strlen(str));
	while (*str)
	{
		if (*str == (char)c)
			last_s = str;
		str++;
	}
	return (last_s);
}
