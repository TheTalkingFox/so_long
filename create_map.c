/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:56:22 by apchelni          #+#    #+#             */
/*   Updated: 2025/02/15 15:55:31 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *mapfile)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), 0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	if (height < 3)
		return (close(fd), ft_printf("Error\nMap: too small or empty\n"), 0);
	else if (height > 18)
		return (close(fd), ft_printf("Error\nMap: too big\n"), 0);
	return (close(fd), height);
}

void	remove_new_line(char *line)
{
	size_t	length;

	length = ft_strlen(line);
	if (length > 0 && line[length - 1] == '\n')
		line[length - 1] = '\0';
}

int	read_map(int fd, t_map *map_info)
{
	char	*line;
	int		line_len;

	map_info->map_width = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		remove_new_line(line);
		line_len = ft_strlen(line);
		if (line_len < 3)
			return (ft_printf("Error\nMap: row is too short\n"), free(line), 0);
		else if (line_len > 38)
			return (ft_printf("Error\nMap: too big\n"), free(line), 0);
		if (map_info->map_width == 0)
			map_info->map_width = line_len;
		else if (line_len != map_info->map_width)
			return (ft_printf("Error\nMap: inconsistent row length\n"),
				free(line), 0);
		map_info->map[map_info->map_height] = line;
		map_info->map_height++;
		line = get_next_line(fd);
	}
	return (1);
}

int	init_map(char *mapfile, t_map *map_info)
{
	int	height;
	int	fd;

	map_info->map_height = 0;
	height = count_lines(mapfile);
	if (height == 0)
		return (0);
	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), 0);
	map_info->map = malloc(height * sizeof(char *));
	if (!map_info->map)
		return (perror("Error allocating memory for the map"), close(fd), 0);
	if (!read_map(fd, map_info) || !check_walls(map_info)
		|| !check_map_content(map_info) || !is_map_reachable(map_info))
		return (free_map(map_info), close(fd), 0);
	return (close(fd), 1);
}

int	handle_input(int argc, char **argv, t_map *map_info)
{
	char	*mapfile;
	int		file_len;

	if (argc != 2)
		return (ft_printf("Error\nInput: wrong number of arguments\n"), 0);
	file_len = ft_strlen(argv[1]);
	mapfile = ft_strnstr(argv[1], ".ber", (size_t)(file_len));
	if (!mapfile || ft_strlen(mapfile) != 4 || file_len - 5 <= 4)
		return (ft_printf("Error\nInput: wrong file\n"), 0);
	if (!init_map(argv[1], map_info))
		return (0);
	return (1);
}
