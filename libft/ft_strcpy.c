/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:42:03 by yochered          #+#    #+#             */
/*   Updated: 2018/10/24 15:42:05 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcpy(char *dst, const char *src)
{
	char *dst_tmp;

	dst_tmp = dst;
	while (*src)
		*dst_tmp++ = *src++;
	*dst_tmp = '\0';
	return (dst);
}
