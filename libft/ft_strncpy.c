/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:23:04 by yochered          #+#    #+#             */
/*   Updated: 2018/10/25 14:23:05 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	src_len;
	size_t	cpy_len;

	src_len = 0;
	cpy_len = len;
	while (src[src_len] != '\0' && len--)
		src_len++;
	if (src_len < cpy_len)
	{
		ft_memcpy(dst, src, src_len);
		ft_memset(dst + src_len, 0, cpy_len - src_len);
	}
	else
		ft_memcpy(dst, src, cpy_len);
	return (dst);
}
