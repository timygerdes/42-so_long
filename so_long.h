/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerdes <tgerdes@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:29:44 by tgerdes           #+#    #+#             */
/*   Updated: 2022/01/10 15:33:55 by tgerdes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>

# ifdef __linux__
#  define UP 119
#  define DOWN 115
#  define RIGHT 97
#  define LEFT 100
#  define ESC 65307
# elif __APPLE__
#  define UP 13
#  define DOWN 1
#  define RIGHT 2
#  define LEFT 0
#  define ESC 53
# endif

typedef struct s_data
{
	void	*img;
}			t_data;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_list	*map;
	int		score;
	int		move_count;
}			t_window;

int		count_lines_in_file(char *file);
int		error_check(int fd, t_list **map, int line_nbr, int *score);
int		check_wall(char *line);
int		check_game_components(char *line, int *map_comps);
int		show_movecount_in_win(t_window *mlx);
int		exit_game(t_window *mlx);
int		handle_key_press(int key, t_window *mlx);
void	create_map(t_window *mlx, t_list *map);
void	draw_background(t_window *mlx, char *line, int line_count);
void	draw_img_to_map(t_window *mlx, char *line, int line_count);
void	draw_floor(t_window *mlx, int x, int y);
void	draw_wall(t_window *mlx, int x, int y);
void	draw_player(t_window *mlx, int x, int y);
void	draw_exit(t_window *mlx, int x, int y);
void	draw_collectible(t_window *mlx, int x, int y);
void	move_player(t_window *mlx, int direction);
char	*next_position(int dir, t_list *line, int counter);
t_list	*find_player(int *counter, t_list *line);
int		check_rectangular(char *file, int total_lines);

#endif