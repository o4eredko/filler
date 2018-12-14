/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:56:28 by yochered          #+#    #+#             */
/*   Updated: 2018/12/10 11:56:29 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_putnstr(char *str, int n)
{
	while (*str && n--)
	{
		ft_putchar(*str);
		str++;
	}
}

void	print_padding(int size, char c)
{
	while (size-- > 0)
		ft_putchar(c);
}

int		print_percent(char c, t_params *params)
{
	int len;

	len = c ? 1 : 0;
	if (params->flag & width)
		len = params->width > len ? params->width : len;
	if (params->flag & width && !(params->flag & minus))
		print_padding(params->width - 1, params->flag & zero ? '0' : ' ');
	if (c)
		ft_putchar(c);
	if (params->flag & width && params->flag & minus)
		print_padding(params->width - 1, ' ');
	return (len);
}
