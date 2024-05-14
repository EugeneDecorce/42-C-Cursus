/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:28:11 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/24 16:08:37 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_image(void *mlx, void *mlx_win, t_coord crd, char c)
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*path;

	if (c == '1')
		path = "./images/wall.xpm";
	if (c == '0')
		path = "./images/background.xpm";
	if (c == 'P')
		path = "./images/me.xpm";
	if (c == 'E')
		path = "./images/exit.xpm";
	if (c == 'C')
		path = "./images/collectible.xpm";
	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	if (img == NULL)
	{
		ft_putstr("Error\nFailed to load image. ");
		ft_putstr(path);
		exit(1);
	}
	mlx_put_image_to_window(mlx, mlx_win, img, crd.x * 25, crd.y * 25);
	mlx_destroy_image(mlx, img);
}
