/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochered <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 10:49:32 by yochered          #+#    #+#             */
/*   Updated: 2018/12/14 10:49:33 by yochered         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_count_digits(int nbr, int base)
{
	int digits;

	digits = 0;
	if (nbr <= 0)
		digits++;
	while (nbr)
	{
		digits++;
		nbr /= base;
	}
	return (digits);
}
