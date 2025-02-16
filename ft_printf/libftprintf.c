/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:38:52 by apchelni          #+#    #+#             */
/*   Updated: 2024/10/25 09:15:20 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_fspec(const char **input, va_list args, int length)
{
	(*input)++;
	if (**input == '%')
		length = handle_char('%');
	else if (**input == '\0')
		return (-1);
	else if (**input == 'c')
		length = handle_char(va_arg(args, int));
	else if (**input == 's')
		length = handle_str(va_arg(args, char *));
	else if (**input == 'd' || **input == 'i')
		length = handle_dec(va_arg(args, int));
	else if (**input == 'u')
		length = handle_un(va_arg(args, unsigned int));
	else if (**input == 'x' || **input == 'X')
		length = handle_hex(va_arg(args, size_t), **input);
	else if (**input == 'p')
		length = handle_p(va_arg(args, void *));
	else
	{
		length = handle_char('%');
		length += handle_char(**input);
	}
	return (length);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		length;
	int		spec_res;

	va_start(args, input);
	length = 0;
	if (!input)
		return (-1);
	while (*input)
	{
		if (*input == '%')
		{
			spec_res = check_fspec(&input, args, length);
			if (spec_res == -1)
				return (-1);
			else
				length += spec_res;
		}
		else
			length += handle_char(*input);
		input++;
	}
	va_end (args);
	return (length);
}
/* 
#include <stdio.h>
int	main()
{
	int	length_ft;

	//int n  = 22;
	//char c = 'a';
	//int n = NULL;
 	int	length_or;
 	length_or = printf ("heyods"); 
	printf("\n%d\n", length_or);
	length_ft = ft_printf("heyods");
	printf("\n%d", length_ft);
} */
