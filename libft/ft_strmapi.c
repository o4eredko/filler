/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:15:20 by yochered          #+#    #+#             */
/*   Updated: 2018/10/27 13:15:22 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fresh_str;
	char	*s_tmp;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	s_tmp = (char *)s;
	fresh_str = (char *)malloc((ft_strlen(s_tmp) + 1) * sizeof(char));
	if (!fresh_str)
		return (NULL);
	while (s_tmp[i] != '\0')
	{
		fresh_str[i] = f(i, s_tmp[i]);
		i++;
	}
	fresh_str[i] = '\0';
	return (fresh_str);
}
