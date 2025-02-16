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

static void	ft_putnbr_hex_p(size_t hex)
{
	char	*hex_low;
	char	ch;

	hex_low = "0123456789abcdef";
	if (hex == 0)
		return ;
	ft_putnbr_hex_p(hex / 16);
	ch = hex_low[hex % 16];
	write (1, &ch, 1);
}

static int	handle_hex_p(size_t hex)
{
	size_t	length;
	size_t	tmp;

	tmp = hex;
	length = 0;
	if (hex == 0)
		length += handle_char('0');
	while (tmp > 0)
	{
		tmp /= 16;
		length++;
	}
	ft_putnbr_hex_p(hex);
	return (length);
}

int	handle_p(void *p)
{
	size_t	length;
	size_t	addr;

	length = 0;
	addr = (size_t)p;
	if (!p)
	{
		write (1, "(nil)", 5);
		length = 5;
	}
	else
	{
		length += write(1, "0x", 2);
		if (addr == 0)
			length += write(1, "0", 1);
		else
			length += handle_hex_p(addr);
	}
	return (length);
}
