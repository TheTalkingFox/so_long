/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:05:22 by apchelni          #+#    #+#             */
/*   Updated: 2024/12/09 23:09:18 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
int			read_line(int fd, char **str, int *str_len, int *size);
int			copy_from_buffer(char *buf, char **str, int *str_len, int *size);
int			increase_size(char **str, int *size, int str_len);
void		update_buffer(char *buf, int start);

#endif