/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:31:35 by yochered          #+#    #+#             */
/*   Updated: 2018/10/24 11:32:05 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char		*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		start;

	len = ft_count_digits(n, 10);
	start = 0;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		start++;
		res[0] = '-';
	}
	res[len--] = '\0';
	while (len >= start)
	{
		if (n > 0)
			res[len--] = n % 10 + 48;
		else
			res[len--] = -(n % 10) + 48;
		n /= 10;
	}
	return (res);
}
