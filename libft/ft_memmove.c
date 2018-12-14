/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:30:49 by yochered          #+#    #+#             */
/*   Updated: 2018/10/25 13:30:52 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;
	size_t			i;

	i = -1;
	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	if (src_tmp < dst_tmp)
	{
		while (len--)
			*(dst_tmp + len) = *(src_tmp + len);
	}
	else
	{
		while (++i < len)
			*(dst_tmp + i) = *(src_tmp + i);
	}
	return (dst);
}
