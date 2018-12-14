/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:36:21 by yochered          #+#    #+#             */
/*   Updated: 2018/12/11 16:36:22 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char		*ft_strjoin_free(char *s1, char *s2)
{
	char	*str_tmp;
	char	*res_tmp;
	char	*res;

	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	str_tmp = s1;
	res_tmp = res;
	while (*s1)
		*res++ = *s1++;
	if (str_tmp)
		free(str_tmp);
	str_tmp = s2;
	while (*s2)
		*res++ = *s2++;
	if (str_tmp)
		free(str_tmp);
	*res = '\0';
	return (res_tmp);
}

void		init_params(t_params *params)
{
	params->e_convert = 0;
	params->e_flags = 0;
	params->flag = 0;
}

intmax_t	ft_power(intmax_t nb, int power)
{
	intmax_t	res;

	res = 1;
	if (power <= 0)
		return (1);
	while (power--)
		res *= nb;
	return (res);
}

double		ft_pow(double nbr, int pow)
{
	double res;

	res = 1;
	while (pow)
	{
		res = pow < 0 ? res / nbr : res * nbr;
		pow += pow < 0 ? 1 : -1;
	}
	return (res);
}
