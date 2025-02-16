/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:26:07 by apchelni          #+#    #+#             */
/*   Updated: 2024/10/25 09:01:09 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *input, ...);
int	handle_char(int c);
int	handle_str(char *str);
int	handle_dec(int n);
int	handle_un(unsigned int un);
int	handle_hex(unsigned int hex, char let_case);
int	handle_p(void *p);

#endif
