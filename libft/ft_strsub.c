/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:27:50 by yochered          #+#    #+#             */
/*   Updated: 2018/10/27 13:27:52 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh_str;
	char	*str;
	size_t	i;

	i = 0;
	fresh_str = (char *)malloc((len + 1) * sizeof(char));
	if (!fresh_str || !s)
		return (NULL);
	str = (char *)s;
	while (str[start] != '\0' && i < len)
		fresh_str[i++] = str[start++];
	fresh_str[i] = '\0';
	return (fresh_str);
}
