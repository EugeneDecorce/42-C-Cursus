/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:22:49 by edecorce          #+#    #+#             */
/*   Updated: 2024/04/22 01:38:57 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>

void	ft_putint(int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);

#endif /* MINITALK_H */