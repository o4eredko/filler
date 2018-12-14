/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:24:59 by yochered          #+#    #+#             */
/*   Updated: 2018/10/26 10:25:01 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*str;
	int		substr_len;

	str = (char *)haystack;
	substr_len = ft_strlen(needle);
	if (substr_len == 0)
		return (str);
	while (*str)
	{
		if (ft_memcmp(str, needle, substr_len) == 0)
			return (str);
		str++;
	}
	return (NULL);
}
