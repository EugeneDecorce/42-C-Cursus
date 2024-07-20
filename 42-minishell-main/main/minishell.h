/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:00:54 by handler           #+#    #+#             */
/*   Updated: 2024/07/20 07:38:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>

extern pid_t	g_signal_pid;

typedef struct s_cmd
{
	int				skip_cmd;
	int				infile;
	int				outfile;
	char			**cmd_param;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}				t_cmd;

typedef struct s_token
{
	char			*str;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}				t_token;

typedef struct s_list
{
	char			*str;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct s_utils
{
	t_list	*env;
	t_token	*token;
	t_cmd	*cmd;
	int		exit_code;
	int		pip[2];
	int	sq;
}				t_utils;

int		ft_pwd(void);
char	*ft_itoa(int n);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isspace(char c);
void	complete_signals();
int		exec(t_utils *data);
void	clear_rl_line(void);
void	clear_rl_line(void);
int		ft_echo(char **args);
size_t	len_cmd(t_cmd *list);
int		is_builtin(char *cmd);
int		ft_isempty(char *str);
int		ft_env(t_list	*env);
void	partial_signals(void);
void	free_array(char **arr);
void	free_cmd(t_cmd **list);
void	handle_sigint(int code);
int		make_env2(t_utils *data);
void	handle_sigabrt(int code);
size_t	ft_lstsize(t_list *list);
void	handle_sigsegv(int code);
int		free_list(t_list **list);
size_t	ft_strlen(const char *s);
void	ft_cmd_status(int status);
char	**lst_to_arr(t_list *env);
int		tokenned_input(char *str);
void	free_token(t_token **list);
void	handle_sigquit(int signum);
char	*ft_strdup(const char *src);
int		create_list_cmd(t_utils *data);
void	sort_array(char **arr, int len);
int		scan_pipes_errors(t_utils *data);
int		append(t_list **list, char *elem);
char	*get_envvar(char *line, int size);
int		ft_unset(char **str, t_list **env);
int		here_doc(t_utils *data, char *word);
int		ft_cd(t_utils *data, char **params);
void	ft_exit(t_utils *data, char **args);
int		make_env(t_utils *data, char **env);
char	*create_paths(t_list *env, int len);
int		ft_export(char **str, t_list **env);
char	*get_envelem(t_list *env, char *key);
int		open_quote(t_utils *data, char *line);
int		replace_env(char **line, t_utils *data);
int		export_variable(char *str, t_list **env);
int		launch_builtin(t_utils *data, t_cmd *cmd);
char	**get_param(t_utils *data, t_token *token);
void	built(int *pip, t_cmd *cmd, t_utils *data);
void	env_constructor(t_utils *data, char **env);
char	*ft_strjoin(char const *s1, char const *s2);
int		exist_in_env(char *line, int *i, t_utils *data);
int		print_error_token(t_token *token, t_utils *data);
int		check_dir(char **path, char *cmd, t_utils *data);
char	*ft_strchr(const char *string, int searchedChar);
int		create_list_token(t_token **begin, char *command);
int		append_token(t_token **list, char *str, int type);
void	child_process(t_utils *data, t_cmd *cmd, int *pip);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	absolute_path(char **path, char *cmd, t_utils *data);
void	redirect_in_out(t_utils *data, t_cmd *cmd, int *pip);
void	quote_selection(int *dq, int *sq, int *index, char c);
int		get_infile(t_utils *data, t_token *token, t_cmd *cmd);
int		get_outfile(t_token *token, t_cmd *cmd, t_utils *data);
char	*find_command(t_utils *data, char *sample, t_list *env);
void	free_data(t_utils *data, char *exit_msg, int exit_code);
int		add_char(char *c, char **str, t_utils *data, int *index);
int		recreate_path(char *dest, char *str, char *env, int *index);
int		add_dollar(char *line, int *index, char **str, t_utils *data);
int		check_command_viability(char **path, t_utils *data, char *cmd);
int		append_cmd(t_cmd **list, int infile, int outfile, char **cmd_param);
void	data_initialisation(t_utils *data, char **env, int argc, char **argv);

#endif
