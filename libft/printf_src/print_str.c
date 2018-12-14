/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:08:38 by yochered          #+#    #+#             */
/*   Updated: 2018/11/29 10:08:39 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	skip_flag_symbols(t_params *params, char **s)
{
	int len;

	len = 0;
	if ((params->flag & hash && (params->type == 'o'))
		|| **s == '+' || **s == '-' || **s == ' ')
		len = 1;
	if (*(*s + 1) == 'x' || *(*s + 1) == 'X' || *(*s + 1) == 'b')
		len = 2;
	ft_putnstr(*s, len);
	params->width -= len;
	*s += len;
}

int		ft_format_str(char *s, t_params *params)
{
	int		len;
	char	*str_tmp;

	len = (int)ft_strlen(s);
	len = params->flag & width && params->width > len ? params->width : len;
	str_tmp = s;
	if (params->flag & width && !(params->flag & minus)
		&& !(params->flag & zero))
		print_padding(params->width - (int)ft_strlen(s), ' ');
	if (params->flag & width && !(params->flag & minus) && params->flag & zero)
	{
		if (params->flag & hash || *s == '+' || *s == '-' || *s == ' '
		|| params->type == 'p')
			skip_flag_symbols(params, &s);
		print_padding(params->width - (int)ft_strlen(s), '0');
	}
	ft_putstr(s);
	if (params->flag & width && params->flag & minus)
		print_padding(params->width - (int)ft_strlen(s), ' ');
	free(str_tmp);
	return (len);
}

int		ft_va_putchar(va_list ap, t_params *params)
{
	int		len;
	char	c;

	c = (char)va_arg(ap, int);
	len = 1;
	if (params->flag & width)
		len = params->width > len ? params->width : len;
	if (params->flag & width && !(params->flag & minus))
		print_padding(params->width - 1, params->flag & zero ? '0' : ' ');
	ft_putchar(c);
	if (params->flag & width && params->flag & minus)
		print_padding(params->width - 1, ' ');
	return (len);
}

int		ft_va_putstr(va_list ap, t_params *params)
{
	char	*s;
	char	*res;

	s = va_arg(ap, char*);
	if (!s)
		s = "(null)";
	res = ft_strdup(s);
	if (params->flag & precision && params->precision < (int)ft_strlen(s))
	{
		s = ft_strsub(res, 0, (size_t)params->precision);
		free(res);
		res = s;
	}
	if (params->flag & hash)
		params->flag = params->flag & ~(1 << (5 - 1));
	return (ft_format_str(res, params));
}
