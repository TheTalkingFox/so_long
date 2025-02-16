/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:56:22 by apchelni          #+#    #+#             */
/*   Updated: 2025/02/15 13:41:52 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_map *map_info)
{
	int	i;

	i = -1;
	while (++i < map_info->map_width)
		if (map_info->map[0][i] != '1' ||
			map_info->map[map_info->map_height - 1][i] != '1')
			return (ft_printf("Error\nMap: invalid wall (up/down)\n"), 0);
	i = -1;
	while (++i < map_info->map_height)
		if (map_info->map[i][0] != '1' ||
			map_info->map[i][map_info->map_width - 1] != '1')
			return (ft_printf("Error\nMap: invalid wall (sides)\n"), 0);
	return (1);
}

int	compare_map_content(t_map *map_info)
{
	if (map_info->start != 1)
		return (ft_printf("Error\nMap: must be 1 start\n"), 0);
	else if (map_info->exit != 1)
		return (ft_printf("Error\nMap: must be 1 exit\n"), 0);
	else if (map_info->collect < 1)
		return (ft_printf("Error\nMap: no collectibles\n"), 0);
	return (1);
}

int	check_map_content(t_map *map_info)
{
	int		i;
	int		j;

	map_info->start = 0;
	map_info->exit = 0;
	map_info->collect = 0;
	i = 0;
	while (++i < map_info->map_height)
	{
		j = 0;
		while (++j < map_info->map_width)
		{
			if (map_info->map[i][j] == 'P')
				map_info->start++;
			else if (map_info->map[i][j] == 'E')
				map_info->exit++;
			else if (map_info->map[i][j] == 'C')
				map_info->collect++;
			else if (map_info->map[i][j] != '0' && map_info->map[i][j] != '1')
				return (ft_printf("Error\nMap: invalid char\n"), 0);
		}
	}
	if (!compare_map_content(map_info))
		return (0);
	return (1);
}
