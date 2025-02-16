/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:56:22 by apchelni          #+#    #+#             */
/*   Updated: 2025/02/15 14:58:40 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	if (!map)
		return ;
	while (++i < map->map_height)
		free(map->map[i]);
	free(map->map);
	map->map = NULL;
	map->map_height = 0;
	map->map_width = 0;
}

void	free_mlx(t_mlx *mlx)
{
	if (mlx->tex.bg)
		mlx_destroy_image(mlx->mlx, mlx->tex.bg);
	if (mlx->tex.wall)
		mlx_destroy_image(mlx->mlx, mlx->tex.wall);
	if (mlx->tex.col)
		mlx_destroy_image(mlx->mlx, mlx->tex.col);
	if (mlx->tex.exit)
		mlx_destroy_image(mlx->mlx, mlx->tex.exit);
	if (mlx->tex.p_exit)
		mlx_destroy_image(mlx->mlx, mlx->tex.p_exit);
	if (mlx->tex.player)
		mlx_destroy_image(mlx->mlx, mlx->tex.player);
	if (mlx->mlx_win)
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	if (mlx->mlx)
		mlx_destroy_display(mlx->mlx);
	free_map(&mlx->map);
	free(mlx->mlx);
	mlx->mlx = NULL;
	exit(1);
}

void	init_mlx_struct(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->mlx_win = 0;
	mlx->img_width = 0;
	mlx->img_height = 0;
	mlx->move_count = 0;
	mlx->col_count = 0;
	mlx->tex.bg = 0;
	mlx->tex.wall = 0;
	mlx->tex.col = 0;
	mlx->tex.exit = 0;
	mlx->tex.p_exit = 0;
	mlx->tex.player = 0;
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	mlx.map.map = NULL;
	if (!handle_input(argc, argv, &mlx.map))
		exit(1);
	init_mlx_struct(&mlx);
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (ft_printf("Error\nAlloc. MiniLibX\n"), free_map(&mlx.map), 0);
	mlx.mlx_win = mlx_new_window(mlx.mlx, mlx.map.map_width * TILE_SIZE,
			mlx.map.map_height * TILE_SIZE, "so_long");
	if (!mlx.mlx_win)
		return (ft_printf("Error\nAlloc. MiniLibX\n"), free_mlx(&mlx), 0);
	if (!init_textures(&mlx))
		free_mlx(&mlx);
	if (!add_background(&mlx) || !add_objects(&mlx))
		free_mlx(&mlx);
	mlx_key_hook(mlx.mlx_win, handle_key_input, &mlx);
	mlx_hook(mlx.mlx_win, 17, 1L << 17, handle_close, &mlx);
	mlx_loop(mlx.mlx);
}
