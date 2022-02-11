/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerdes <tgerdes@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:54:50 by tgerdes           #+#    #+#             */
/*   Updated: 2022/01/09 19:07:41 by tgerdes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_background(t_window *mlx, char *line, int line_count)
{
	int	x;
	int	y;

	x = 0;
	y = line_count;
	while (*line)
	{
		draw_floor(mlx, x * 50, y * 50);
		line++;
		x++;
	}
}

void	draw_img_to_map(t_window *mlx, char *line, int line_count)
{
	int	x;
	int	y;

	x = 0;
	y = line_count;
	while (*line)
	{
		if (*line == '0')
			draw_floor(mlx, x * 50, y * 50);
		if (*line == '1')
			draw_wall(mlx, x * 50, y * 50);
		if (*line == 'P')
			draw_player(mlx, x * 50, y * 50);
		if (*line == 'E')
			draw_exit(mlx, x * 50, y * 50);
		if (*line == 'C')
			draw_collectible(mlx, x * 50, y * 50);
		line++;
		x++;
	}
}

void	create_map(t_window *mlx, t_list *map)
{
	t_list	*f_lst;
	t_list	*s_lst;
	int		map_height;
	int		i;

	i = 0;
	f_lst = map;
	s_lst = map;
	map_height = ft_lstsize(map);
	while (i < map_height)
	{
		draw_background(mlx, f_lst->content, i);
		f_lst = f_lst->next;
		i++;
	}
	i = 0;
	while (i < map_height)
	{
		draw_img_to_map(mlx, s_lst->content, i);
		s_lst = s_lst->next;
		i++;
	}
}
