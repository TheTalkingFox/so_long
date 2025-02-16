/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:01:11 by apchelni          #+#    #+#             */
/*   Updated: 2024/10/18 13:01:46 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int n)
{
	char	ch;

	if (n < 0)
	{
		n = -n;
		write (1, "-", 1);
	}
	if (n >= 0 && n <= 9)
		ch = n + '0';
	else
	{
		ft_putnbr(n / 10);
		ch = n % 10 + '0';
	}
	write (1, &ch, 1);
}

int	handle_dec(int n)
{
	size_t	length;
	int		tmp;

	length = 0;
	tmp = n;
	if (tmp <= 0)
	{
		if (tmp == -2147483648)
		{
			write (1, "-2147483648", 11);
			return (11);
		}
		tmp = -tmp;
		length++;
	}
	while (tmp > 0)
	{
		tmp /= 10;
		length++;
	}
	ft_putnbr(n);
	return (length);
}
