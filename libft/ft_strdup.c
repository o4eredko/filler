/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:32:48 by yochered          #+#    #+#             */
/*   Updated: 2018/10/24 15:32:50 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strdup(const char *s1)
{
	char	*dest;
	char	*dest_tmp;
	int		len;

	len = ft_strlen(s1);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest_tmp = dest;
	while (*s1)
		*dest++ = *s1++;
	*dest = '\0';
	return (dest_tmp);
}
