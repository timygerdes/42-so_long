/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerdes <tgerdes@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:57:52 by tgerdes           #+#    #+#             */
/*   Updated: 2022/01/10 00:00:41 by tgerdes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	show_movecount_in_win(t_window *mlx)
{
	char	*move_count;

	move_count = ft_itoa((*mlx).move_count);
	mlx_string_put((*mlx).mlx, (*mlx).mlx_win, 10, 20, 0xFFFFFF, \
	move_count);
	free(move_count);
	return (0);
}

int	exit_game(t_window *mlx)
{
	if ((*mlx).map)
		ft_lstclear(&(*mlx).map, free);
	mlx_destroy_window((*mlx).mlx, (*mlx).mlx_win);
	free((*mlx).mlx);
	exit(0);
}
