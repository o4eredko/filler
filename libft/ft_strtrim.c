/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:52:56 by yochered          #+#    #+#             */
/*   Updated: 2018/10/27 13:52:57 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static int	is_space(char c)
{
	if (c == ' ' || c == ',' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static int	count_len(char const *s)
{
	int len;
	int i;

	len = ft_strlen(s);
	while (is_space(s[len - 1]))
		len--;
	i = -1;
	while (is_space(s[++i]))
		len--;
	if (len < 0)
		len = 0;
	return (len);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*res;

	if (!s)
		return (NULL);
	i = -1;
	len = count_len(s);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (is_space(*s))
		s++;
	while (++i < len)
		res[i] = *s++;
	res[i] = '\0';
	return (res);
}
