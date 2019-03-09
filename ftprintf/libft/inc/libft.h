/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:01:46 by jmeier            #+#    #+#             */
/*   Updated: 2019/03/08 16:08:36 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 4096
# define ASSERT(a) if (!(a)) return (-1);
# define NULL_GUARD(a) if (!(a)) return (NULL);
# define MATCH(a,b) if (a) b
# define OR(a,b) else if (a) b
# define OTHERWISE(a) else a
# define ANY2(x,a,b) (x == a || x == b)
# define ANY3(x,a,b,c) (x == a || x == b || x == c)
# define ANY4(x,a,b,c,d) (x == a || x == b || x == c || x == d)
# define ANY5(x,a,b,c,d,e) (x == a || x == b || x == c || x == d || x == e)
# define SE(a, b) ft_strequ(a, b)
# define MAX(a, b) (a > b ? a : b)
# define MIN(a, b) (a < b ? a : b)

# define TRUE 1
# define FALSE 0

# define RES "\033[0m"
# define B "\033[1m"
# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define MAG "\033[35m"
# define CYA "\033[36m"
# define WHI "\033[37m"


typedef struct		s_node
{
	void			*content;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

typedef struct		s_queue
{
	t_node			*first;
	t_node			*last;
}					t_queue;

typedef struct		s_block
{
	char			*buf;
	char			*str;
	char			*tmp;
	int				len;
	int				fd;
	struct s_block	*next;
}					t_block;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_map
{
	void			**data;
	unsigned		count;
	unsigned		capacity;
	unsigned		key_size;
}					t_map;

/*
** Stack and Queue
*/

t_stack				*ft_stack_init(void);
void				*ft_stack_pop(t_stack *s);
void				ft_stack_push(t_stack *s, void *content);
void				*ft_stack_peek(t_stack *s);
int					ft_stack_isempty(t_stack *s);

/*
** Utility
*/

int					get_next_line(const int fd, char **line);
size_t				get_file_contents(char *filename, char **fill);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(char c);
int					ft_isascii(int c);
int					ft_isvalue(char c);
int					ft_ishex(char c);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);
int					ft_count_words(char *str, char c);
int					ft_sqrt(unsigned int nb);
double				ft_sqroot(double square);
int					ft_pow(int nb, int ex);
int					ft_atoi_base(char *nb, int base);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_error(char *str);
void				ft_qsort(void *arr[], int size, int (*comp)(const void *, const void*));
int					ft_compare_str(const void *a, const void *b);
int					ft_compare_int(const void *a, const void *b);


/*
** Hashmap
*/

uint32_t			ft_fnv32(const uint8_t *data, size_t size);
uint64_t			ft_fnv64(const uint8_t *data, size_t size);
uint32_t			ft_map_hash(t_map *m, const char *key);
void				ft_map_init(t_map *map, unsigned int key_size, unsigned int
size);
void				*ft_map_get(t_map *m, uint32_t hash);
void				ft_map_set(t_map *m, uint32_t hash, void *ptr);
void				*ft_map_remove(t_map *m, uint32_t hash);
void				ft_map_resize(t_map *m, unsigned size);
void				map_place_link(void **new, unsigned bucket_index, t_list
*link);
void				ft_map_clean(t_map *m, void (*free_fn)(void *));

/*
** String
*/

char				*ft_strcat(char *dst, const char *src);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strctrim(const char *s, char c);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strfjoin(char *s1, char const *s2);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *big, const char *lil, size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
int					ft_stricmp(char const *a, char const *b);
int					ft_strchr_ind(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
void				ft_strtoupper(char **s);
void				ft_strtolower(char **s);
void				ft_strappend(char **src, char *add);

/*
** Memory
*/

void				*ft_memalloc(size_t size);
void				*ft_realloc(void *ptr, size_t new_size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t byte);
void				*ft_memset(void *s, int c, size_t n);
char				**ft_arrdup(char **arr);
void				ft_freearr(char **array);
void				ft_free(void *ptr);

/*
** Linked Lists
*/

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
int					ft_lstnodecheck(t_list *l1, t_list *l2);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_lstpush(t_list **lst, void *content, size_t size);
void				*ft_lstpop(t_list **lst);

/*
** Printing and length
*/

void				ft_ld(long n);
void				ft_puthex(unsigned long long n);
void				ft_putlhex(unsigned long long n);
void				ft_putoct(unsigned long long n);
void				ft_putull(unsigned long long n);
void				ft_putnbrf(int n);
int					ft_numlen(int n, int base);
int					ft_unumlen(unsigned int n, int base);
int					ft_longlen(long n, int base);
int					ft_ulonglen(unsigned long n, int base);
int					ft_longlonglen(long long n, int base);
int					ft_ulonglonglen(unsigned long long n, int base);
void				ft_putstrn(char *s, int n);
void				ft_putwstr(wchar_t *str);
void				ft_putchar(char c);
void				ft_putchars(char c, int amt);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_base_fd(int n, int base, int fd);
void				ft_putnbr_base(int n, int base);
void				ft_putnbr_base_lc(int n, int base, int fd);
void				ft_putunbr_base(unsigned int n, unsigned int base);
void				ft_putunbr_base_fd(unsigned int n, unsigned int base,
																	int fd);
void				ft_putunbr_base_lc(unsigned int n, unsigned int base,
																	int fd);
void				ft_putlong(long n, long base, int fd);
void				ft_putlong_lc(unsigned long n, unsigned long base, int fd);
void				ft_putlonglong(long long n, long long base, int fd);
void				ft_putlonglong_lc(unsigned long long n,
												unsigned long long b, int fd);
void				ft_putulong(unsigned long n, unsigned long base, int fd);
void				ft_putulonglong(unsigned long long n,
												unsigned long long b, int fd);
void				ft_putstr(char *s);
void				ft_putstr_fd(char const *s, int fd);
#endif
