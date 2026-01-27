/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:32:12 by muhakhan          #+#    #+#             */
/*   Updated: 2026/01/26 23:11:55 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define HISTORY_FILE "test.txt"
# define CWD_BUFFER_SIZE 1024

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <dirent.h>
# include <termios.h>
# include <limits.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>

typedef enum e_token_type
{
	TOK_EOF,
	TOK_WORD,
	TOK_PIPE,
	TOK_AND,
	TOK_SEMI_COL,
	TOK_LT,
	TOK_GT,
	TOK_DGT,
	TOK_DLT,
	TOK_LPAREN,
	TOK_RPAREN,
	TOK_QUOTES,
	TOK_UNKNOWN
}	t_token_type;

typedef struct s_token
{
	char			*token;
	int				type;
	struct s_token	*next;
}	t_token;

typedef struct s_redir
{
	int				type;
	char			*file;
	struct s_redir	*next;
}	t_redir;

typedef struct s_command
{
	char				**args;
	t_redir				*redirs;
	int					is_builtin;
	int					exit_status;
	struct s_command	*next;
}	t_command;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_data
{
	t_env	*env_list;
	char	*user_input;
	int		last_exit_code;
	char	*working_dir;
}	t_data;

int		my_pwd(char **args);
int		builtin_env(char **args, t_data *data);
int		builtin_exit(char **args, t_data *data);
int		builtin_unset(char **args, t_data *data);
int		builtin_cd(char **args, t_data *data);
int		builtin_echo(char **args);
int		builtin_export(char **args, t_data *data);
t_env	*init_env(char **envp);
char	*get_env_value(t_data *data, char *key);
int		is_numeric(char *str);
void	free_env_list(t_env *head);
void	free_shell_data(t_data *data);
void	ft_free_split(char **split);
int		execute_builtin(char **args, t_data *data);
char	*find_command_path(char *cmd, t_data *data);
int		execute_external_command(char **args, char **envp, t_data *data);
int		apply_redirections(t_redir *redirs);
void	execute_pipeline(t_command *cmds, t_data *data);
char	*skip_whitespaces(char *input);
char	**env_list_to_envp(t_env *env);
t_token	*lexer(char *input);
int		parse_loop(void);
void	clean_exit(int stage, char *msg);
void	handle_sigint(void);
void	setup_interactive_signals(void);
void	init_shell_data(t_data *data, char **envp);


#endif