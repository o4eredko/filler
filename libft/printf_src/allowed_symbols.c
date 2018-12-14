/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed_symbols.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:19:30 by yochered          #+#    #+#             */
/*   Updated: 2018/12/04 15:19:31 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		flag_list(char c)
{
	return (c == '+' || c == '-' || c == ' ' || c == '0' || c == '#');
}

int		convert_list(char c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 'L' || c == 'z');
}

int		allowed_symbols(char *format)
{
	if (!flag_list(*format) && *format != '*' && *format != '.'
		&& type_id(*format, NULL) == -1 && !convert_list(*format)
		&& !ft_isdigit(*format) && *format != '%')
		return (0);
	return (1);
}
