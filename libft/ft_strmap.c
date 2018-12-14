/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:13:12 by yochered          #+#    #+#             */
/*   Updated: 2018/10/27 13:13:13 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *fresh_str;
	char *fresh_str_tmp;
	char *s_tmp;

	if (!s)
		return (NULL);
	s_tmp = (char *)s;
	fresh_str = (char *)malloc((ft_strlen(s_tmp) + 1) * sizeof(char));
	if (!fresh_str)
		return (NULL);
	fresh_str_tmp = fresh_str;
	while (*s_tmp)
	{
		*fresh_str++ = f(*s_tmp);
		s_tmp++;
	}
	*fresh_str = '\0';
	return (fresh_str_tmp);
}
