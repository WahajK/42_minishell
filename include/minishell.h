/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:32:12 by muhakhan          #+#    #+#             */
/*   Updated: 2025/12/04 16:14:16 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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


// ====================================================================
// 2. COMMAND STRUCTURE (The core contract between Parser and Executor)
// ====================================================================

// Structure to hold a single command and its execution context
typedef struct s_command
{
    char            **args;         // Array of strings: command and its arguments (e.g., {"ls", "-l", NULL}).
    //t_redir         *redirs;        // Linked list of all redirections for this command.
    int             is_builtin;     // Flag (0 or 1) to indicate if the command is a shell builtin.
    int             exit_status;    // Field to store the exit status of this specific command after execution.
    //struct s_command *next;         // Pointer to the next command in the pipeline (for the '|' operator).
} t_command;

typedef struct s_env
{
	char	*key;
	char	*value;
	struct	s_env	*next;
}	t_env;


typedef struct s_data
{
    t_env           *env_list;      // The head of your custom environment linked list
    char            *user_input;    // The raw line read from readline
    int             last_exit_code; // The value of $?
    char            *working_dir;   // Current working directory (optional, but useful)
    // Add other necessary state here later (e.g., signal handlers, etc.)
} t_data;

#define CWD_BUFFER_SIZE 1024

// #builtins

int	my_pwd(t_command *cmd);
int builtin_env(t_command *cmd, t_data *data);
int	builtin_exit(t_command *cmd, t_data *data);


// #env
t_env	*init_env(char **envp);
char	*get_env_value(t_data *data, char *key);

//#utils
int	is_numeric(char *str);
void	free_env_list(t_env *head);
void	free_shell_data(t_data *data);

int		skip_whitespaces(char *input);
t_token	*lexer(char *input);
void	parse_loop(void);
void	init_signals(void);
void	sig_handler(int signum, siginfo_t *info, void *context);
void	clean_exit(int stage, char *msg);
void	handle_sigquit(void *context);
void	handle_sigint(void *context);
#endif