/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:14:46 by yochered          #+#    #+#             */
/*   Updated: 2018/10/27 15:14:51 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

static int	count_words(char const *s, char c)
{
	int words;
	int	len;
	int i;

	words = 0;
	i = -1;
	len = ft_strlen(s);
	while (++i < len)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
	}
	return (words);
}

static int	count_len(char const *s, char c)
{
	int len;

	len = 0;
	while (*s == c)
		s++;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	if (!s || !(res = (char **)malloc(sizeof(*res) * (count_words(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < count_words(s, c))
	{
		k = 0;
		if (!(res[i] = ft_strnew(count_len(&s[j], c))))
			res[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			res[i][k++] = s[j++];
	}
	res[i] = 0;
	return (res);
}
