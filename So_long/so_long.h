/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:11:01 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/28 11:44:47 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx/mlx.h"

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_key_hook_param
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	int		*total;
}	t_key_hook_param;

void				ft_putint(int n);
void				ft_putchar(char c);
void				ft_putstr(char *str);
int					ft_strlen(char *str);
void				free_map(char **map);
char				*ft_strdup(const char *s);
int					ft_strcountchar(char *str, char c);
void				duplicate_map(char **map, char ***map_copy);
void				create_map(char ***map, int row, int *col, char *file);

char				*get_next_line(int fd);
char				*ft_strjoin(char *s1, char *s2);
int					get_next_return_index(char *buffer, int start_index);
char				*extract_line(char *str, int start_index, int *index);

int					line_contain_only(char *line, char c);
int					line_head_tail_character(char *line, int c);
void				check_line_contain_invalid_character(char *line, int fd);

void				check_args_count(int argc);
void				check_invalid_map_rank2(char **map);
void				check_invalid_map_rank1(char *map, int *row);

t_coord				gen_coordinates(int x, int y);
int					total_collectibles(char **map);
int					close_hook(t_key_hook_param *param);
void				display(char **map, int row, int col);
t_coord				get_current_position(char **map, char c);
void				put_frame(char **map, void *mlx, void *mlx_win);
int					key_hook(int keycode, t_key_hook_param *params);
void				put_image(void *mlx, void *mlx_win, t_coord crd, char c);
t_key_hook_param	gen_key_hook_param(void *mlx, void *mlx_win,
						char **map, int *total);
void				is_valid_action(int valid_key,
						t_key_hook_param *params, t_coord new);

#endif /* SO_LONG_H */