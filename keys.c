/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerdes <tgerdes@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:57:43 by tgerdes           #+#    #+#             */
/*   Updated: 2022/01/09 18:58:32 by tgerdes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key_press(int key, t_window *mlx)
{
	if (key == UP || key == LEFT || key == DOWN || key == RIGHT)
	{
		move_player(mlx, key);
		create_map(mlx, (*mlx).map);
	}
	else if (key == ESC)
		exit_game(mlx);
	return (0);
}
