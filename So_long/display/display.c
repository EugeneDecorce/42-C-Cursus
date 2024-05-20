/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:25:30 by edecorce          #+#    #+#             */
/*   Updated: 2024/05/19 19:53:38 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_frame(char **map, void *mlx, void *mlx_win)
{
	t_coord	crd;

	crd.y = 0;
	while (map[crd.y])
	{
		crd.x = 0;
		while (map[crd.y][crd.x])
		{
			if (map[crd.y][crd.x] != 'E')
				put_image(mlx, mlx_win, crd, map[crd.y][crd.x]);
			else
				put_image(mlx, mlx_win, crd, '0');
			(crd.x) += 1;
		}
		(crd.y) += 1;
	}
}

void	display_collectibles(int total)
{
	ft_putint(total);
	if (total == 1)
		ft_putstr(" worm eaten\n");
	else
		ft_putstr(" worms eaten\n");
}

void	is_valid_action(int valid_key, t_key_hook_param *params, t_coord new)
{
	t_coord	coordinatesp;
	t_coord	coordinatese;

	coordinatesp = get_current_position(params->map, 'P');
	coordinatese = get_current_position(params->map, 'E');
	if (valid_key && params->map[new.y][new.x] != '1')
	{
		if (params->map[new.y][new.x] == 'C')
		{
			*(params->total) += 1;
			display_collectibles(*(params->total));
			if (total_collectibles(params->map) == 1)
				put_image(params->mlx, params->mlx_win, coordinatese, 'E');
		}
		// if (params->map[new.y][new.x] == 'E')
		// 	free_map(params->map);
		// if (params->map[new.y][new.x] == 'E')
		// 	exit(0);
		put_image(params->mlx, params->mlx_win, new, 'P');
		params->map[new.y][new.x] = 'P';
		put_image(params->mlx, params->mlx_win, coordinatesp, '0');
		params->map[coordinatesp.y][coordinatesp.x] = '0';
	}
}

int	redraw(t_key_hook_param *params)
{
	put_frame(params->map, params->mlx, params->mlx_win);
	return (0);
}

void	display(char **map, int row, int col)
{
	void				*mlx;
	void				*win;
	int					collected;
	t_key_hook_param	params;

	mlx = mlx_init();
	win = mlx_new_window(mlx, col * 25, row * 25, "So long");
	put_frame(map, mlx, win);
	collected = 0;
	params = gen_key_hook_param(mlx, win, map, &collected);
	mlx_hook(win, 2, 1L << 0, key_hook, &params);
	mlx_hook(win, 17, 1L << 17, close_hook, &params);
	mlx_hook(win, 12, 1L << 15, (int (*)())redraw, &params);
	mlx_loop(mlx);
}
