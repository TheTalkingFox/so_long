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

int	handle_str(char *str)
{
	size_t	length;

	length = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		length = 6;
	}
	else if (*str)
		while (str[length])
			length += write (1, &str[length], 1);
	return (length);
}
