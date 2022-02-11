/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerdes <tgerdes@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:56:09 by tgerdes           #+#    #+#             */
/*   Updated: 2022/01/09 13:48:19 by tgerdes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_floor(t_window *mlx, int x, int y)
{
	void	*img;
	char	*path_name;
	int		size;

	size = 50;
	path_name = "assets/floor.xpm";
	img = mlx_xpm_file_to_image(mlx, path_name, &size, &size);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, x, y);
}

void	draw_wall(t_window *mlx, int x, int y)
{
	void	*img;
	char	*path_name;
	int		size;

	size = 50;
	path_name = "assets/wall.xpm";
	img = mlx_xpm_file_to_image(mlx, path_name, &size, &size);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, x, y);
}

void	draw_player(t_window *mlx, int x, int y)
{
	void	*img;
	char	*path_name;
	int		size;

	size = 50;
	path_name = "assets/player.xpm";
	img = mlx_xpm_file_to_image(mlx, path_name, &size, &size);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, x, y);
}

void	draw_exit(t_window *mlx, int x, int y)
{
	void	*img;
	char	*path_name;
	int		size;

	size = 50;
	path_name = "assets/exit.xpm";
	img = mlx_xpm_file_to_image(mlx, path_name, &size, &size);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, x, y);
}

void	draw_collectible(t_window *mlx, int x, int y)
{
	void	*img;
	char	*path_name;
	int		size;

	size = 50;
	path_name = "assets/collectible.xpm";
	img = mlx_xpm_file_to_image(mlx, path_name, &size, &size);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, x, y);
}
