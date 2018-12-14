/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 11:55:48 by yochered          #+#    #+#             */
/*   Updated: 2018/12/08 11:55:49 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_va_putbinary(va_list ap, t_params *params)
{
	uintmax_t	nbr;
	int			len;
	char		*res;
	char		*res_tmp;

	nbr = convert_unsigned_arg(ap, params);
	len = count_unsigned_digits(nbr, 2);
	if (params->flag & precision)
		len = len < params->precision ? params->precision : len;
	res = ft_strnew((size_t)len);
	if (!(!nbr && (params->flag & precision && !params->precision)))
		uint_to_str(res, nbr, 2, params);
	res_tmp = res;
	if (params->flag & hash && nbr > 0)
	{
		res = ft_strnew(2);
		ft_strcp(res, "0b");
		res = ft_strjoin_free(res, res_tmp);
	}
	if (params->flag & zero && params->flag & precision)
		params->flag = params->flag & ~(1 << (3 - 1));
	return (ft_format_str(res, params));
}

char	*get_str_22_to_32(char c)
{
	if (c == 22)
		return ("[syn]");
	else if (c == 23)
		return ("[etb]");
	else if (c == 24)
		return ("[can]");
	else if (c == 25)
		return ("[em]");
	else if (c == 26)
		return ("[sub]");
	else if (c == 27)
		return ("[esc]");
	else if (c == 28)
		return ("[fs]");
	else if (c == 29)
		return ("[gs]");
	else if (c == 30)
		return ("[rs]");
	else if (c == 31)
		return ("[us]");
	else if (c == 32)
		return ("[sp]");
	else if (c == 127)
		return ("[del]");
	return (NULL);
}

char	*get_str_11_to_21(char c)
{
	if (c == 11)
		return ("[vt]");
	else if (c == 12)
		return ("[np]");
	else if (c == 13)
		return ("[cr]");
	else if (c == 14)
		return ("[so]");
	else if (c == 15)
		return ("[si]");
	else if (c == 16)
		return ("[dle]");
	else if (c == 17)
		return ("[dc1]");
	else if (c == 18)
		return ("[dc2]");
	else if (c == 19)
		return ("[dc3]");
	else if (c == 20)
		return ("[dc4]");
	else if (c == 21)
		return ("[nak]");
	else
		return (get_str_22_to_32(c));
}

char	*get_str(char c)
{
	if (c == 0)
		return ("[nul]");
	else if (c == 1)
		return ("[soh]");
	else if (c == 2)
		return ("[stx]");
	else if (c == 3)
		return ("[etx]");
	else if (c == 4)
		return ("[eot]");
	else if (c == 5)
		return ("[enq]");
	else if (c == 6)
		return ("[ack]");
	else if (c == 7)
		return ("[bel]");
	else if (c == 8)
		return ("[bs]");
	else if (c == 9)
		return ("[ht]");
	else if (c == 10)
		return ("[nl]");
	else
		return (get_str_11_to_21(c));
}

int		ft_va_putnonprint(va_list ap, t_params *params)
{
	char	*s;
	char	*res;
	int		len;

	s = va_arg(ap, char*);
	len = (int)ft_strlen(s);
	res = ft_strnew(1);
	while (len--)
	{
		res = ft_strjoin_free(res, ft_strdup(get_str(*s)));
		s++;
	}
	return (ft_format_str(res, params));
}
