NAME = minishell

SRCS = src/main.c src/parser/main_parser.c src/signals/init_signals.c src/signals/sig_handlers.c src/utils/clean_exit.c src/get_next_line/get_next_line.c
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