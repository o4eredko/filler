/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:30:22 by yochered          #+#    #+#             */
/*   Updated: 2018/10/30 14:30:23 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	print_hex(unsigned char c)
{
	char	hex_digits[16];
	int		i;
	char	n;

	i = 0;
	n = '0';
	while (n <= '9')
		hex_digits[i++] = n++;
	n = 'a';
	while (n <= 'f')
		hex_digits[i++] = n++;
	hex_digits[i] = '\0';
	ft_putchar(hex_digits[c / 16]);
	ft_putchar(hex_digits[c % 16]);
}

static void	print_ascii(unsigned char c)
{
	if (c >= 32 && c <= 126)
		ft_putchar(c);
	else
		ft_putchar('.');
}

static void	print_line(unsigned char *str, size_t min, size_t max)
{
	size_t i;

	i = min;
	while (i < min + 16 && i < max)
	{
		print_hex(str[i]);
		if (i % 2 != 0)
			ft_putchar(' ');
		i++;
	}
	while (i < min + 16)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if (i % 2 != 0)
			ft_putchar(' ');
		i++;
	}
	i = min;
	while (i < min + 16 && i < max)
	{
		print_ascii(str[i]);
		i++;
	}
	ft_putchar('\n');
}

void		ft_print_memory(const void *addr, size_t size)
{
	size_t			c;
	unsigned char	*str;

	c = 0;
	str = (unsigned char *)addr;
	while (c < size)
	{
		print_line(str, c, size);
		c += 16;
	}
}
