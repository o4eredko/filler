/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:25:19 by yochered          #+#    #+#             */
/*   Updated: 2018/12/04 18:25:20 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		get_limit(char *res, long double nbr, t_params *params)
{
	if (nbr != nbr)
		ft_strcp(res, "nan");
	else if (nbr == 1.0 / 0.0)
		ft_strcp(res, "inf");
	else if (nbr == -1.0 / 0.0)
		ft_strcp(res, "inf");
	*(res + 3) = '\0';
	if (params->type == 'F')
		str_toupper(res);
	if (params->flag & zero)
		params->flag = params->flag & ~(1 << (3 - 1));
}

int			ft_int_to_str(intmax_t nbr, char *res, int precision)
{
	int i;

	i = 0;
	while (nbr)
	{
		res[i++] = (char)((nbr < 0 ? -(nbr % 10) : nbr % 10) + '0');
		nbr /= 10;
	}
	while (i < precision)
		res[i++] = '0';
	ft_strrev(res, i);
	return (i);
}

void		ft_dtoa(long double nbr, char *res, int precision)
{
	int			i;
	int			k;

	nbr += 0.5 / ft_pow(10, precision);
	i = ft_int_to_str((intmax_t)nbr, res, 1);
	nbr -= (intmax_t)nbr;
	k = -1;
	if (precision)
	{
		res[i++] = '.';
		while (++k < precision)
		{
			nbr *= 10;
			res[i++] = (char)((int)nbr + 48);
			nbr -= (int)nbr;
		}
	}
	res[i] = '\0';
}

char		*putfloat(long double nbr, t_params *params)
{
	char	*res;

	res = ft_strnew(((size_t)count_signed_digits((intmax_t)nbr, 10)
		+ 1 + (params->flag & precision ? params->precision : 6)));
	if ((nbr < 0 || (!nbr && 1.0 / nbr == 1.0 / -0.0) || params->flag & plus
		|| params->flag & space) && nbr == nbr)
	{
		if (nbr < 0 || (!nbr && 1.0 / nbr == 1.0 / -0.0))
			*res++ = '-';
		else
			*res++ = (char)(params->flag & space
				&& !(params->flag & plus) ? ' ' : '+');
	}
	if (nbr != nbr || nbr == 1.0 / 0.0 || nbr == -1.0 / 0.0)
		get_limit(res, nbr, params);
	else
		ft_dtoa(ABS(nbr), res, params->flag & precision
			? params->precision : 6);
	if (params->flag & precision && !params->precision && params->flag & hash)
		*(res + ft_strlen(res)) = '.';
	if ((nbr < 0 || (!nbr && 1.0 / nbr == 1.0 / -0.0) || params->flag & plus
		|| params->flag & space) && nbr == nbr)
		res--;
	return (res);
}

int			ft_va_putfloat(va_list ap, t_params *params)
{
	long double	nbr;
	char		*res;

	if (params->e_convert == L)
		nbr = va_arg(ap, long double);
	else
		nbr = va_arg(ap, double);
	res = putfloat(nbr, params);
	return (ft_format_str(res, params));
}
