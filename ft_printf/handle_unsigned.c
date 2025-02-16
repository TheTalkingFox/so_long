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

static void	ft_putnbr_un(unsigned int un)
{
	char	ch;

	if (un <= 9)
		ch = un + '0';
	else
	{
		ft_putnbr_un(un / 10);
		ch = un % 10 + '0';
	}
	write (1, &ch, 1);
}

int	handle_un(unsigned int un)
{
	size_t			length;
	unsigned int	tmp;

	length = 0;
	tmp = un;
	if (tmp == 0)
		length++;
	while (tmp > 0)
	{
		tmp /= 10;
		length++;
	}
	ft_putnbr_un(un);
	return (length);
}
