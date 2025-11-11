/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:53:33 by muhakhan          #+#    #+#             */
/*   Updated: 2025/05/22 23:08:45 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_node
{
	int				push_cost;
	int				index;
	int				data;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
}	t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_lstsize(t_node *lst);
int		ft_putnbr_base(unsigned long nbr, char *base);
int		print_address(unsigned long addr);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(long long int n, int fd);
int		ft_printf(const char *format, ...);
int		ft_strcmp(const char *s1, const char *s2);
long	ft_atol(const char *str, int *error);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
t_list	*ft_lstlast(t_list *lst);
t_node	*ft_lstnew(int data);
t_list	*ft_lstinit(void);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_itoa(int n);
char	*ft_strdup(const char *src);
char	*strnstr(const char *big, const char *little, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putendl_fd(char *s, int fd);
void	ft_lstadd_back(t_node **head, t_node **tail, t_node *new);
void	ft_lstadd_front(t_node **head, t_node **tail, t_node *new);
void	ft_lstdelone(t_node *node);
void	ft_lstclear(t_node **head, t_node **tail);
void	ft_lstiter(t_list *lst, void (*f)(void *));

#endif
