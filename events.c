/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:56:22 by apchelni          #+#    #+#             */
/*   Updated: 2025/02/15 15:42:30 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_close(t_mlx *mlx)
{
	free_mlx(mlx);
	return (0);
}

int	move_player_x(t_mlx *mlx, int dir)
{
	if (mlx->map.map[mlx->map.pl_y][mlx->map.pl_x + dir] != '1')
	{
		ft_printf("Number of movements: %d\n", ++mlx->move_count);
		if (mlx->map.map[mlx->map.pl_y][mlx->map.pl_x + dir] == 'C')
			mlx->col_count++;
		if (mlx->map.map[mlx->map.pl_y][mlx->map.pl_x + dir] != 'E')
			mlx->map.map[mlx->map.pl_y][mlx->map.pl_x + dir] = 'P';
		if (mlx->map.map[mlx->map.pl_y][mlx->map.pl_x] != 'E')
		{
			mlx->map.map[mlx->map.pl_y][mlx->map.pl_x] = '0';
			if (mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->tex.bg,
					mlx->map.pl_x * TILE_SIZE, mlx->map.pl_y * TILE_SIZE) != 0)
				free_mlx(mlx);
			return (1);
		}
		else if (mlx->map.map[mlx->map.pl_y][mlx->map.pl_x] == 'E')
		{
			if (mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->tex.exit,
					mlx->map.pl_x * TILE_SIZE, mlx->map.pl_y * TILE_SIZE) != 0)
				free_mlx(mlx);
			return (1);
		}
	}
	return (0);
}

int	move_player_y(t_mlx *mlx, int dir)
{
	if (mlx->map.map[mlx->map.pl_y + dir][mlx->map.pl_x] != '1')
	{
		ft_printf("Number of movements: %d\n", ++mlx->move_count);
		if (mlx->map.map[mlx->map.pl_y + dir][mlx->map.pl_x] == 'C')
			mlx->col_count++;
		if (mlx->map.map[mlx->map.pl_y + dir][mlx->map.pl_x] != 'E')
			mlx->map.map[mlx->map.pl_y + dir][mlx->map.pl_x] = 'P';
		if (mlx->map.map[mlx->map.pl_y][mlx->map.pl_x] != 'E')
		{
			mlx->map.map[mlx->map.pl_y][mlx->map.pl_x] = '0';
			if (mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->tex.bg,
					mlx->map.pl_x * TILE_SIZE, mlx->map.pl_y * TILE_SIZE) != 0)
				free_mlx(mlx);
			return (1);
		}
		else if (mlx->map.map[mlx->map.pl_y][mlx->map.pl_x] == 'E')
		{
			if (mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->tex.exit,
					mlx->map.pl_x * TILE_SIZE, mlx->map.pl_y * TILE_SIZE) != 0)
				free_mlx(mlx);
			return (1);
		}
	}
	return (0);
}

int	handle_key_input(int key, t_mlx *mlx)
{
	if (key == 65307)
		free_mlx(mlx);
	else if (key == 119 || key == 65362)
		mlx->map.pl_y -= move_player_y(mlx, -1);
	else if (key == 115 || key == 65364)
		mlx->map.pl_y += move_player_y(mlx, 1);
	else if (key == 100 || key == 65363)
		mlx->map.pl_x += move_player_x(mlx, 1);
	else if (key == 97 || key == 65361)
		mlx->map.pl_x -= move_player_x(mlx, -1);
	if (mlx->map.map[mlx->map.pl_y][mlx->map.pl_x] == 'E')
	{
		if (mlx->col_count == mlx->map.collect)
			free_mlx(mlx);
		else
			if (mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
					mlx->tex.p_exit, mlx->map.pl_x * TILE_SIZE, mlx->map.pl_y
					* TILE_SIZE) != 0)
				free_mlx(mlx);
	}
	else if (mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->tex.player,
			mlx->map.pl_x * TILE_SIZE, mlx->map.pl_y * TILE_SIZE) != 0)
		free_mlx(mlx);
	return (0);
}
