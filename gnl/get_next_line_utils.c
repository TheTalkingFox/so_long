/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:41:39 by apchelni          #+#    #+#             */
/*   Updated: 2025/02/02 18:28:09 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	increase_size(char **str, int *size, int str_len)
{
	char	*new_str;
	int		j;

	(*size) += BUFFER_SIZE;
	new_str = NULL;
	new_str = malloc((*size + 1) * sizeof(char));
	if (!new_str)
	{
		write(2, "Error\nGetNextLine fail\n", 23);
		return (0);
	}
	j = -1;
	while (++j < str_len)
		new_str[j] = (*str)[j];
	free(*str);
	*str = new_str;
	return (1);
}

int	copy_from_buffer(char *buf, char **str, int *str_len, int *size)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (*str_len >= *size)
			if (!increase_size(str, size, *str_len))
				return (-1);
		(*str)[(*str_len)++] = buf[i++];
		if (buf[i - 1] == '\n')
			break ;
	}
	return (i);
}

void	update_buffer(char *buf, int start)
{
	int	j;

	j = 0;
	while (buf[start] != '\0')
		buf[j++] = buf[start++];
	buf[j] = '\0';
}

int	read_line(int fd, char **str, int *str_len, int *size)
{
	static char	buf[BUFFER_SIZE + 1];
	int			copied_len;
	int			bytes_read;

	if (buf[0] == '\0')
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (-1);
		if (bytes_read == 0)
		{
			if (*str_len == 0)
				return (0);
			return (1);
		}
		buf[bytes_read] = '\0';
	}
	copied_len = copy_from_buffer(buf, str, str_len, size);
	if (copied_len < 0)
		return (-1);
	update_buffer(buf, copied_len);
	if (*str_len > 0 && (*str)[*str_len - 1] == '\n')
		return (1);
	return (2);
}
