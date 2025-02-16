/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:56:28 by apchelni          #+#    #+#             */
/*   Updated: 2025/02/15 13:44:21 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_SIZE 48

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>

typedef struct s_textures
{
	void		*wall;
	void		*bg;
	void		*col;
	void		*player;
	void		*exit;
	void		*p_exit;
}				t_textures;

typedef struct s_map
{
	char		**map;
	int			map_width;
	int			map_height;
	int			start;
	int			exit;
	int			collect;
	int			pl_x;
	int			pl_y;
}				t_map;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	int			img_width;
	int			img_height;
	t_textures	tex;
	t_map		map;
	int			move_count;
	int			col_count;
}				t_mlx;

typedef struct s_point
{
	int			y;
	int			x;
}				t_point;

typedef struct s_map_check
{
	int			**visited;
	t_point		*queue;
	int			front;
	int			back;
	int			directions[4][2];
	int			sp_tiles;
}				t_map_check;

int				handle_input(int argc, char **argv, t_map *map_info);
int				init_map(char *mapfile, t_map *map_info);
int				read_map(int fd, t_map *map_info);
void			remove_new_line(char *line);
int				count_lines(char *mapfile);
int				check_map_content(t_map *map_info);
int				compare_map_content(t_map *map_info);
int				check_walls(t_map *map_info);
int				is_map_reachable(t_map *map_info);
void			is_player(t_map *map_info);
int				create_queue(t_point **queue, t_map *map_info);
int				create_visited_array(int ***visited, t_map *map_info);
void			free_visited_array(int **visited, t_map *map_info);
void			free_map(t_map *map);
void			init_directions(int directions[4][2]);
void			run_bfs(t_map_check *map_check, t_map *map_info);
int				check_neighbors(t_map_check *map_check, t_map *map_info,
					t_point current);
void			count_sp_tiles(t_map_check *map_check, t_map *map_info, int nx,
					int ny);
int				init_textures(t_mlx *mlx);
int				add_objects(t_mlx *mlx);
int				add_background(t_mlx *mlx);
int				handle_key_input(int key, t_mlx *mlx);
int				move_player_y(t_mlx *mlx, int dir);
int				move_player_x(t_mlx *mlx, int dir);
int				handle_close(t_mlx *mlx);
void			free_mlx(t_mlx *mlx);
#endif