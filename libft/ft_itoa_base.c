/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:17:41 by yochered          #+#    #+#             */
/*   Updated: 2018/10/29 16:17:42 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int	count_digits(int value, int base)
{
	int digits;

	digits = 0;
	if (value < 0 && base == 10)
		digits++;
	if (value == 0)
		digits++;
	while (value != 0)
	{
		digits++;
		value /= base;
	}
	return (digits);
}

char		*ft_itoa_base(int value, int base)
{
	char	*res;
	char	*base_digits;
	int		digits;

	if (!(base_digits = (char *)malloc(16 * sizeof(char))))
		return (NULL);
	base_digits = "0123456789ABCDEF";
	digits = count_digits(value, base);
	if (!(res = (char *)malloc((digits + 1) * sizeof(char))))
		return (NULL);
	if (value < 0 && base == 10)
		res[0] = '-';
	if (value == 0)
		res[0] = '0';
	res[digits] = '\0';
	while (value && digits-- > 0)
	{
		res[digits] = value < 0 ? base_digits[-(value % base)] :
			base_digits[(value % base)];
		value /= base;
	}
	return (res);
}
