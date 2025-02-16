/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:41:39 by apchelni          #+#    #+#             */
/*   Updated: 2025/02/02 18:20:52 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*str;
	int		str_len;
	int		size;
	int		status;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = NULL;
	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str_len = 0;
	size = BUFFER_SIZE;
	while (1)
	{
		status = read_line(fd, &str, &str_len, &size);
		if (status <= 0)
			return (free(str), NULL);
		else if (status == 1)
			break ;
	}
	str[str_len] = '\0';
	return (str);
}
/* 
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf ("%s", line);
		free(line);
	}
	close(fd);
} */
