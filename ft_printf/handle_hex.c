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

static void	ft_putnbr_hex(unsigned int hex, char let_case)
{
	char	*hex_low;
	char	*hex_up;
	char	ch;

	hex_low = "0123456789abcdef";
	hex_up = "0123456789ABCDEF";
	if (hex == 0)
		return ;
	ft_putnbr_hex(hex / 16, let_case);
	if (let_case == 'x')
		ch = hex_low[hex % 16];
	else if (let_case == 'X')
		ch = hex_up[hex % 16];
	write (1, &ch, 1);
}

int	handle_hex(unsigned int hex, char let_case)
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
	ft_putnbr_hex(hex, let_case);
	return (length);
}
