/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:04:14 by yochered          #+#    #+#             */
/*   Updated: 2018/11/29 10:04:16 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

uintmax_t	convert_unsigned_arg(va_list ap, t_params *params)
{
	uintmax_t nbr;

	nbr = va_arg(ap, uintmax_t);
	if (params->e_convert == hh)
		nbr = (unsigned char)nbr;
	else if (params->e_convert == h)
		nbr = (unsigned short)nbr;
	else if (params->e_convert == l)
		nbr = (unsigned long)nbr;
	else if (params->e_convert == ll)
		nbr = (unsigned long long)nbr;
	else if (params->e_convert == j)
		nbr = (uintmax_t)nbr;
	else if (params->e_convert == z)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

int			ft_va_putunbr(va_list ap, t_params *params)
{
	char		*str;
	uintmax_t	nbr;
	size_t		len;

	nbr = convert_unsigned_arg(ap, params);
	len = (size_t)count_unsigned_digits(nbr, 10);
	if (params->flag & precision)
		len = (int)len < params->precision ? params->precision : len;
	str = ft_strnew(len);
	uint_to_str(str, nbr, 10, params);
	if (params->flag & hash)
		params->flag = params->flag & ~(1 << (5 - 1));
	if (params->flag & zero && params->flag & precision)
		params->flag = params->flag & ~(1 << (3 - 1));
	return (ft_format_str(str, params));
}

int			ft_va_putoctal(va_list ap, t_params *params)
{
	char		*str;
	char		*str_tmp;
	uintmax_t	nbr;
	size_t		len;

	nbr = convert_unsigned_arg(ap, params);
	len = (size_t)count_unsigned_digits(nbr, 8);
	if (params->flag & precision)
		len = (int)len < params->precision ? params->precision : len;
	str = ft_strnew(len);
	str_tmp = str;
	if (!(!nbr && (params->flag & precision && !params->precision)))
		uint_to_str(str, nbr, 8, params);
	if (params->flag & hash && (nbr > 0 || params->flag & precision)
		&& (!(params->flag & precision)
	|| params->precision <= count_unsigned_digits(nbr, 8)))
	{
		str = ft_strnew(1);
		ft_strcp(str, "0");
		str = ft_strjoin_free(str, str_tmp);
	}
	if (params->flag & zero && params->flag & precision)
		params->flag = params->flag & ~(1 << (3 - 1));
	return (ft_format_str(str, params));
}

int			ft_va_puthex(va_list ap, t_params *params)
{
	char		*str;
	char		*str_tmp;
	uintmax_t	nbr;
	size_t		len;

	nbr = convert_unsigned_arg(ap, params);
	len = (size_t)count_unsigned_digits(nbr, 16);
	if (params->flag & precision)
		len = (int)len < params->precision ? params->precision : len;
	str = ft_strnew(len);
	str_tmp = str;
	if (!(!nbr && (params->flag & precision && !params->precision)))
		uint_to_str(str, nbr, 16, params);
	if (params->flag & hash && nbr > 0)
	{
		str = ft_strnew(2);
		ft_strcp(str, "0x");
		str = ft_strjoin_free(str, str_tmp);
	}
	if (params->flag & zero && params->flag & precision)
		params->flag = params->flag & ~(1 << (3 - 1));
	if (params->type == 'X')
		str_toupper(str);
	return (ft_format_str(str, params));
}
