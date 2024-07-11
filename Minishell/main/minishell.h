/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:14:55 by edecorce          #+#    #+#             */
/*   Updated: 2024/07/10 22:56:03 by edecorce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAX_ARGS 64
# define MAX_PATH_LENGTH 1024

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>

// User commands
void	handle_redirections(char **args);
void	handle_heredoc(char *delimiter);
char	*find_in_path(const char *command);
char	**parse_user_input(char *input);
void	exec_command(char *input);

// Built-Ins
void	ft_env(void);
void	ft_pwd(void);
void	ft_cd(char *input);
void	ft_exit(char *input);
void	ft_echo(char *input);
void	ft_unset(char *input);
void	ft_export(char *input);
void	ft_cmd_status(int status);
int		is_echo_option(char *input, int i);

// Signals
void	signal_constructor(void);
void	signal_constructor2(void);
void	sigint_handler(int signum);
void	sigint_handler2(int signum);

// Main
void	input_manager(char *input);
void	minishell_init(char **input);
void	command_not_found(char *input);
int		check_command(char *input, char *test);

// Redirections
int		forward(char *input);
char	*ft_forward_output(char *str);
int		ft_forward_output_len(char *str);
int		forward_redirection_errors(char *input);
int		backward_redirection_errors(char *input);
char	*ft_forward_file(char *input, char *sep);

// Quotes
char	*remove_quotes(char *input);
int		is_in_quote(char *str, int index);

// Utils
char	*ft_itoa(int n);
int		ft_isspace(int c);
int		ft_isalpha(char c);
int		ft_strlen(char	*str);
int		ft_isnumber(char *str);
void	ft_freemap(char **map);
char	*ft_fetchenv(char *str);
int		ft_atoi(const char *str);
char	*ft_strtrim(char *input);

int	ft_strcmp(const char *str1, const char *str2);
int		is_empty_string(char *str);
int		env_delim(char *str, int i);
int		ft_strtrim_len(char *input);
char	*ft_strdup(const char *src);
int		env_delim_noq(char *str, int i);
int		ft_subchar(char *str, char *sub);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strndup(const char *src, size_t n);
char	*ft_substr(char *str, int from, int to);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strtok(char *str, const char *delim);
int		is_last_characters(char *input, int index);
size_t	ft_strspn(const char *str, const char *delim);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_execvp(const char *file, char *const argv[]);
size_t	ft_strcspn(const char *str, const char *reject);
int		next_occ(char *str, int i, char *sep, int reverse);
int		next_occ_noq(char *str, int i, char *sep, int reverse);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
int		ft_contains(char *str, int from_index, int to_index, char c);
int		ft_snprintf(char *str, size_t size, const char *format, ...);
int		ft_contains_seq(char *str, int from_index, int to_index, char *seq);
void	ft_strtrim_helper(int *in_dquote, int *in_squote, char *input, int i);
int		forward_helper(char **output, char *input, char **file1, char **file2);

#endif /* MINISHELL_H */