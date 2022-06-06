/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:26:40 by nmordeka          #+#    #+#             */
/*   Updated: 2022/06/06 11:02:18 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	error_exit(char	*err_message, int exit_code, int errno)
{
	if (exit_code)
	{
		ft_putendl_fd("Error", 2);
		if (err_message)
			ft_putendl_fd(err_message, 2);
		else
			ft_putendl_fd(strerror(errno), 2);
	}
	//sleep(20);
	exit(exit_code);
}

static void	free_map(char **map)
{
	// size_t	i;

	// i = -1;
	if (map)
	{
		/* while (map[++i])
			free(map[i]); */
		free(map);
	}
}

void free_decor(t_decor *decor, void *mlx)
{
	if (!decor)
		return ;
	ft_free_sprite(decor->south, mlx);
	ft_free_sprite(decor->north, mlx);
	ft_free_sprite(decor->east, mlx);
	ft_free_sprite(decor->west, mlx);
	free (decor);
}

void	game_exit(t_game *game, char *err_mess, int code, int fd)
{
	if (game)
	{
		if (game->map)
			free_map(game->map);
		if (game->decor)
			free_decor(game->decor, game->mlx);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		free(game);
	}
	
	if (fd > 0)
		close (fd);
		//sleep(20);
	error_exit(err_mess, code, 1);
}