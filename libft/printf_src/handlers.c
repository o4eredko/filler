/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:31:32 by yochered          #+#    #+#             */
/*   Updated: 2018/12/11 16:31:38 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		handle_flags(char **format, t_params *params)
{
	char	*flags;
	int		i;

	flags = FLAGS;
	while (flag_list(**format))
	{
		i = -1;
		while (flags[++i])
			if (flags[i] == **format)
				params->flag |= ft_power(2, i);
		(*format)++;
	}
}

void		handle_width(char **format, t_params *params, va_list ap)
{
	if (**format == '*')
	{
		params->width = va_arg(ap, int);
		params->flag |= width;
		(*format)++;
	}
	else if (ft_isdigit(**format))
	{
		params->width = ft_atoi(*format);
		params->flag |= width;
		while (ft_isdigit(**format))
			(*format)++;
	}
	if (params->flag & width && params->width < 0)
	{
		params->flag |= minus;
		params->width = -params->width;
	}
}

void		handle_precision(char **format, t_params *params, va_list ap)
{
	if (**format == '.' && *(*format + 1) == '*')
	{
		params->precision = va_arg(ap, int);
		params->flag |= params->precision >= 0 ? precision : 0;
		(*format) += 2;
	}
	else if (**format == '.' && ft_isdigit(*(*format + 1)))
	{
		(*format)++;
		params->precision = ft_atoi(*format);
		params->flag |= params->precision >= 0 ? precision : 0;
		while (ft_isdigit(**format))
			(*format)++;
	}
	else if (**format == '.' && !ft_isdigit(*(*format + 1)))
	{
		(*format)++;
		params->precision = 0;
		params->flag |= params->precision >= 0 ? precision : 0;
	}
}

void		handle_length(char **format, t_params *params)
{
	if (**format == 'h' && *(*format + 1) != 'h' && params->e_convert < h)
		params->e_convert = h;
	else if (**format == 'h' && *(*format + 1) == 'h')
		params->e_convert = hh;
	else if (**format == 'l' && *(*format + 1) != 'l' && params->e_convert < l)
		params->e_convert = l;
	else if (**format == 'l' && *(*format + 1) == 'l' && params->e_convert < ll)
		params->e_convert = ll;
	else if (**format == 'j' && params->e_convert < j)
		params->e_convert = j;
	else if (**format == 'z' && params->e_convert < z)
		params->e_convert = z;
	else if (**format == 'L')
		params->e_convert = L;
	(*format) += params->e_convert == hh || params->e_convert == ll ? 2 : 1;
}

void		reach_type(const char **format, t_params *params, va_list ap)
{
	while (allowed_symbols((char*)*format) &&
		type_id(**format, NULL) == -1 && **format != '%')
	{
		if (flag_list(**format))
			handle_flags((char**)format, params);
		else if (ft_isdigit(**format) || **format == '*')
			handle_width((char**)format, params, ap);
		else if (**format == '.')
			handle_precision((char**)format, params, ap);
		else if (convert_list(**format))
			handle_length((char**)format, params);
	}
}
