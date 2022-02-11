/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerdes <tgerdes@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:57:49 by tgerdes           #+#    #+#             */
/*   Updated: 2022/01/09 19:02:00 by tgerdes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*find_player(int *counter, t_list *line)
{
	t_list	*curr;

	curr = line->next;
	while (curr->next)
	{
		*counter = 0;
		while (*(char *)(curr->content + *counter) != 'P' \
		&& *(char *)(curr->content + *counter))
			*counter = *counter + 1;
		if (*(char *)(curr->content + *counter) == 'P')
			break ;
		line = curr;
		curr = curr->next;
	}
	return (line);
}

char	*next_position(int dir, t_list *line, int counter)
{
	char	*currdir;

	currdir = (char *)(ft_lstlast(line)->content);
	if (dir == UP)
		currdir = (char *)(line->content + counter);
	else if (dir == LEFT)
		currdir = (char *)(line->next->content + counter - 1);
	else if (dir == RIGHT)
		currdir = (char *)(line->next->content + counter + 1);
	else if (dir == DOWN)
		currdir = (char *)(line->next->next->content + counter);
	return (currdir);
}

void	move_player(t_window *mlx, int direction)
{
	t_list	*line;
	char	*new_pos;
	int		counter;

	line = find_player(&counter, (*mlx).map);
	new_pos = next_position(direction, line, counter);
	if (*new_pos != '1')
	{
		if (*new_pos == 'C')
			(*mlx).score = (*mlx).score - 1;
		else if (*new_pos == 'E' && (*mlx).score == 0)
			exit_game(mlx);
		else if (*new_pos == 'E')
			return ;
		*new_pos = 'P';
		*(char *)(line->next->content + counter) = '0';
		(*mlx).move_count = (*mlx).move_count + 1;
	}
	return ;
}
