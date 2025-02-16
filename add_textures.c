/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:56:22 by apchelni          #+#    #+#             */
/*   Updated: 2025/02/15 15:41:26 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	add_background(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->map.map_height * TILE_SIZE)
	{
		x = 0;
		while (x < mlx->map.map_width * TILE_SIZE)
		{
			if (!mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->tex.bg, x,
					y))
				return (ft_printf("Error\nPut BG to window\n"), 0);
			x += mlx->img_width;
		}
		y += mlx->img_height;
	}
	return (1);
}

int	put_img(t_mlx *mlx, int i, int j)
{
	if (mlx->map.map[i][j] == '1')
	{
		if (!mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->tex.wall, j
				* TILE_SIZE, i * TILE_SIZE))
			return (ft_printf("Error\nPut wall to window\n"), 0);
	}
	else if (mlx->map.map[i][j] == 'C')
	{
		if (!mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->tex.col, j
				* TILE_SIZE, i * TILE_SIZE))
			return (ft_printf("Error\nPut collect. to window\n"), 0);
	}
	else if (mlx->map.map[i][j] == 'E')
	{
		if (!mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->tex.exit, j
				* TILE_SIZE, i * TILE_SIZE))
			return (ft_printf("Error\nPut exit to window\n"), 0);
	}
	else if (mlx->map.map[i][j] == 'P')
	{
		if (!mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->tex.player, j
				* TILE_SIZE, i * TILE_SIZE))
			return (ft_printf("Error\nPut player to window\n"), 0);
	}
	return (1);
}

int	add_objects(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mlx->map.map_height)
	{
		j = -1;
		while (++j < mlx->map.map_width)
			if (!put_img(mlx, i, j))
				return (0);
	}
	return (1);
}

int	init_textures(t_mlx *mlx)
{
	mlx->tex.bg = mlx_xpm_file_to_image(mlx->mlx, "textures/BG.xpm",
			&mlx->img_width, &mlx->img_height);
	if (!mlx->tex.bg)
		return (ft_printf("Error\nBG texture not found\n"), 0);
	mlx->tex.wall = mlx_xpm_file_to_image(mlx->mlx, "textures/wall.xpm",
			&mlx->img_width, &mlx->img_height);
	if (!mlx->tex.wall)
		return (ft_printf("Error\nWall texture not found\n"), 0);
	mlx->tex.col = mlx_xpm_file_to_image(mlx->mlx, "textures/col.xpm",
			&mlx->img_width, &mlx->img_height);
	if (!mlx->tex.col)
		return (ft_printf("Error\nCollect.texture not found\n"), 0);
	mlx->tex.player = mlx_xpm_file_to_image(mlx->mlx, "textures/pl.xpm",
			&mlx->img_width, &mlx->img_height);
	if (!mlx->tex.player)
		return (ft_printf("Error\nPlayer texture not found\n"), 0);
	mlx->tex.exit = mlx_xpm_file_to_image(mlx->mlx, "textures/exit.xpm",
			&mlx->img_width, &mlx->img_height);
	if (!mlx->tex.exit)
		return (ft_printf("Error\nExit texture not found\n"), 0);
	mlx->tex.p_exit = mlx_xpm_file_to_image(mlx->mlx, "textures/p_on_exit.xpm",
			&mlx->img_width, &mlx->img_height);
	if (!mlx->tex.p_exit)
		return (ft_printf("Error\nPlayer on exit texture not found\n"), 0);
	return (1);
}
