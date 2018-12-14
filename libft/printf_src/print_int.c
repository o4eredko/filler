/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:19:04 by yochered          #+#    #+#             */
/*   Updated: 2018/12/04 16:19:05 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

intmax_t	convert_signed_arg(va_list ap, t_params *params)
{
	intmax_t nbr;

	nbr = va_arg(ap, intmax_t);
	if (params->e_convert == hh)
		nbr = (char)nbr;
	else if (params->e_convert == h)
		nbr = (short)nbr;
	else if (params->e_convert == l)
		nbr = (long)nbr;
	else if (params->e_convert == ll)
		nbr = (long long)nbr;
	else if (params->e_convert == j)
		nbr = (intmax_t)nbr;
	else if (params->e_convert == z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

int			ft_va_putnbr(va_list ap, t_params *params)
{
	char		*str;
	char		*str_tmp;
	intmax_t	nbr;
	size_t		len;

	nbr = convert_signed_arg(ap, params);
	len = (size_t)count_signed_digits(nbr, 10);
	if (params->flag & precision)
		len = len < (size_t)params->precision ? (size_t)params->precision : len;
	if (((params->flag & plus || params->flag & space) && nbr >= 0) || nbr < 0)
		str = ft_strnew(len + 1);
	else
		str = ft_strnew(len);
	str_tmp = str;
	if (params->flag & space && !(params->flag & plus) && nbr >= 0)
		*str_tmp++ = ' ';
	if (params->flag & plus && nbr >= 0)
		*str_tmp++ = '+';
	if (!(!nbr && (params->flag & precision && !params->precision)))
		int_to_str(str_tmp, nbr, 10, params);
	if (params->flag & hash)
		params->flag = params->flag & ~(1 << (5 - 1));
	if (params->flag & zero && params->flag & precision)
		params->flag = params->flag & ~(1 << (3 - 1));
	return (ft_format_str(str, params));
}
