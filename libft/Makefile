NAME = libft.a

SRCS = \
	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_strchr.c ft_strjoin.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
	ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_tolower.c \
	ft_toupper.c ft_memchr.c ft_memcmp.c ft_strdup.c \
	ft_substr.c ft_calloc.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putchar_fd.c ft_putnbr_fd.c ft_split.c ft_striteri.c \
	ft_strmapi.c ft_itoa.c ft_printf.c ft_strcmp.c \
	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	ft_lstclear.c ft_lstdelone.c ft_lstnew.c ft_lstinit.c \
	ft_lstsize.c ft_atol.c get_next_line.c

OBJ = $(SRCS:.c=.o)
BOBJECTS = $(BONUSSRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $@ $?

clean:
	rm -f $(OBJ) $(BOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re