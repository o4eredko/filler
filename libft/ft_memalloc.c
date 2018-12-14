/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:16:03 by yochered          #+#    #+#             */
/*   Updated: 2018/10/25 11:16:22 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <libft.h>

void	*ft_memalloc(size_t size)
{
	void	*mem_area;

	if (!(mem_area = (unsigned char *)malloc(size * sizeof(unsigned char))))
		return (NULL);
	mem_area = (unsigned char *)ft_memset(mem_area, 0, size);
	return (mem_area);
}
