/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:10:30 by yochered          #+#    #+#             */
/*   Updated: 2018/10/26 11:10:32 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	size_t	substr_len;

	substr_len = ft_strlen(needle);
	str = (char *)haystack;
	if (substr_len == 0)
		return (str);
	while (*str && len-- >= substr_len)
	{
		if (ft_memcmp(str, needle, substr_len) == 0)
			return (str);
		str++;
	}
	return (NULL);
}
