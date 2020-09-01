/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:11:57 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:11:58 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include "get_next_line.h"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_putchar(char c);
void			ft_putnbr(int n);
void			ft_putstr(char const *s);
int				ft_strcmp(char const *s1, char const *s2);
int				ft_strncmp(char const *s1, char const *s2, size_t n);
size_t			ft_strlen(char const *s);
char			**ft_split_whitespaces(char *str);
int				ft_atoi(char const *str);
char			*ft_strdup(char const *str);
char			*ft_strndup(char const *str, size_t n);
char			*ft_strcat(char *dest, char const *src);
char			*ft_strncat(char *dest, char const *src, size_t n);
size_t			ft_strlcat(char *dest, char const *src, size_t size);
char			*ft_strstr(char const *s1, char const *s2);
char			*ft_strnstr(char const *s1, char const *s2, size_t n);
char			*ft_strncpy(char *dest, char const *src, size_t lenn);
char			*ft_strcpy(char *dest, char const *src);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(char const *s, int c);
char			*ft_strrchr(char const *s, int c);
void			ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_memset(void *s, int c, size_t n);
void			ft_memdel(void **ap);
void			*ft_memcpy(void *dest, void const *src, size_t n);
void			*ft_memccpy(void *dest, void const *src, int c, size_t n);
int				ft_memcmp(void const *dest, void const *src, size_t n);
void			*ft_memchr(void const *s, int c, size_t n);
void			*ft_memmove(void *dest, void const *src, size_t n);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
char			**ft_strsplit(char const *s, char c);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strmap(char const *s, char(*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strsub(char const *s, unsigned intstart, size_t len);
char			*ft_strjoin(char const *s1, char const*s2);
char			*ft_strtrim(char const *s);
void			ft_putendl(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strrev(char *str);
int				ft_recursive_power(int nb, int power);
int				ft_sqrt(int nb);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			*ft_realloc(void *ptr, size_t size);
void			putstrsub(char const *s, int starts, size_t len);
void			ft_putnbr_base(long n, unsigned base);
void			ft_putnbr_base_maj(long n, unsigned base);
void			ft_putnbr_l(long n);
void			ft_putnbr_lu(unsigned long n);
void			ft_putnbr_u(unsigned int n);
void			ft_put_address(unsigned long nb, unsigned int base, int i);
void			ft_putfloat(float nb);
char			*ft_itoa_base(int n, unsigned int base);
char			*ltoa(long n);
char			*ft_ltoa_base(long n, unsigned int base);
char			*ft_ltoa_base_maj(long n, unsigned int base);
long			power_of_ten(long n);
size_t			number_of_digit(long n);
int				ft_intchr(char const *s, char const *accept);
char			*char_to_str(char c);
char			*add_n_char_at_pos(char c, char *str, size_t n, size_t pos);
int				find_char_in_str(char c, char *str);
void			ft_putnbr_base_u(unsigned long n, unsigned base);
size_t			number_of_digit_base(long i, unsigned int base);
size_t			number_of_digit_base_u(unsigned long i, unsigned int base);
void			ft_putnbr_base_u_maj(unsigned long n, unsigned base);
void			putfloat_prec(float f, unsigned int p);
int				tab_2d_len(char **tab);
long long		ft_atol(char const *str);
int				*split_int(char *s);
int				max_int_tab(int *tab, unsigned int size);
int				min_int_tab(int *tab, unsigned int size);
int				pos_max_int_tab(int *tab, unsigned int size);
int				pos_min_int_tab(int *tab, unsigned int size);
void			sort_integer_table(int *tab, unsigned int size);
int				count_char_in_str(char c, char *str);
int				check_tri_tab(int *tab, int size);
int				check_tri_tab_reverse(int *tab, int size);
int				number_of_number_in_str(char *str);
long			ft_abs(long n);
int				poeist(int x, int *tab, int size);
void			free_2d_char(char **t);
char			*ft_strjoinfree(char *d, char *s, int d_s);

#endif
