/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:56:22 by apchelni          #+#    #+#             */
/*   Updated: 2025/02/15 13:44:13 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_sp_tiles(t_map_check *map_check, t_map *map_info, int ny, int nx)
{
	if (map_info->map[ny][nx] == 'C' || map_info->map[ny][nx] == 'E')
		map_check->sp_tiles++;
}

int	check_neighbors(t_map_check *map_check, t_map *map_info, t_point current)
{
	int	nx;
	int	ny;
	int	i;

	i = -1;
	while (++i < 4)
	{
		ny = current.y + map_check->directions[i][0];
		nx = current.x + map_check->directions[i][1];
		if (ny >= 0 && ny < map_info->map_height && nx >= 0
			&& nx < map_info->map_width && !map_check->visited[ny][nx]
			&& map_info->map[ny][nx] != '1')
		{
			if (map_check->back < map_info->map_height * map_info->map_width)
			{
				map_check->queue[map_check->back++] = (t_point){ny, nx};
				map_check->visited[ny][nx] = 1;
			}
			else
				return (ft_printf("Error\nMap: queue overflow\n"), 0);
			count_sp_tiles(map_check, map_info, ny, nx);
		}
	}
	return (1);
}

void	run_bfs(t_map_check *map_check, t_map *map_info)
{
	t_point	current;

	map_check->sp_tiles = 0;
	while (map_check->front < map_check->back)
	{
		current = map_check->queue[map_check->front++];
		check_neighbors(map_check, map_info, current);
	}
}

void	init_directions(int directions[4][2])
{
	directions[0][0] = 0;
	directions[0][1] = 1;
	directions[1][0] = 1;
	directions[1][1] = 0;
	directions[2][0] = 0;
	directions[2][1] = -1;
	directions[3][0] = -1;
	directions[3][1] = 0;
}
