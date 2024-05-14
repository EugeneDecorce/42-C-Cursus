/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:46:43 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/24 17:35:26 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H

void	*mlx_init(void);
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
			int x, int y);
int		mlx_loop (void *mlx_ptr);
void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
			int *width, int *height);
int		mlx_destroy_image(void *mlx_ptr, void *img_ptr);
int		mlx_hook(void *win_ptr, int x_event, int x_mask,
			int (*funct)(), void *param);

#endif /* MLX_H */
