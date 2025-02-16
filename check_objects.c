/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:56:22 by apchelni          #+#    #+#             */
/*   Updated: 2025/02/15 13:44:27 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_player(t_map *map_info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_info->map_height)
	{
		j = -1;
		while (++j < map_info->map_width)
		{
			if (map_info->map[i][j] == 'P')
			{
				map_info->pl_y = i;
				map_info->pl_x = j;
			}
		}
	}
}

void	free_visited_array(int **visited, t_map *map_info)
{
	int	i;

	i = -1;
	while (++i < map_info->map_height)
		free(visited[i]);
	free(visited);
	visited = NULL;
}

int	create_visited_array(int ***visited, t_map *map_info)
{
	int	i;

	*visited = ft_calloc(map_info->map_height, sizeof(int *));
	if (!*visited)
		return (perror("Error allocating memory for the visited array"), 0);
	i = -1;
	while (++i < map_info->map_height)
	{
		(*visited)[i] = ft_calloc(map_info->map_width, sizeof(int));
		if (!(*visited)[i])
			return (perror("Error allocating memory for the visited array"),
				free_visited_array(*visited, map_info), 0);
	}
	return (1);
}

int	create_queue(t_point **queue, t_map *map_info)
{
	*queue = malloc(map_info->map_height * map_info->map_width
			* sizeof(t_point));
	if (!*queue)
		return (perror("Error allocating memory for the queue"), 0);
	return (1);
}

int	is_map_reachable(t_map *map_info)
{
	t_map_check	map_check;

	is_player(map_info);
	if (!create_visited_array(&map_check.visited, map_info))
		return (0);
	if (!create_queue(&map_check.queue, map_info))
		return (free_visited_array(map_check.visited, map_info), 0);
	map_check.front = 0;
	map_check.back = 0;
	map_check.queue[map_check.back++] = (t_point){map_info->pl_y,
		map_info->pl_x};
	init_directions(map_check.directions);
	map_check.visited[map_info->pl_y][map_info->pl_x] = 1;
	run_bfs(&map_check, map_info);
	free(map_check.queue);
	free_visited_array(map_check.visited, map_info);
	if (map_check.sp_tiles != map_info->collect + map_info->exit)
		return (ft_printf("Error\nMap: some objects unreachable\n"), 0);
	return (1);
}
