NAME = minishell

SRCS = src/main.c \
       src/parser/main_parser.c \
       src/parser/lexer.c \
       src/parser/parser.c \
       src/parser/parser_command.c \
       src/parser/parser_redirect.c \
       src/parser/parser_utils.c \
       src/parser/parser_expand.c \
       src/builtin/builtin_cd.c \
       src/builtin/builtin_echo.c \
       src/builtin/builtin_env.c \
       src/builtin/builtin_exit.c \
       src/builtin/builtin_export.c \
       src/builtin/builtin_pwd.c \
       src/builtin/builtin_unset.c \
       src/env/env_init.c \
       src/execution/exec_dispatch.c \
       src/execution/execution_envp.c \
       src/execution/execution_path.c \
       src/execution/execution_pipeline.c \
       src/execution/execution_process.c \
       src/execution/execution_redir.c \
       src/execution/heredoc.c \
       src/signals/signal.c \
       src/utils/clean_exit.c \
       src/utils/ft_utils.c \
       src/get_next_line/get_next_line.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = #-Wall -Wextra -Werror
READLINE = -lreadline
LIBFT = libft/libft.a
LIBFT_DIR = libft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(READLINE)

$(LIBFT):
	make -C $(LIBFT_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all