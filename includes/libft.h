/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:35:40 by cghael            #+#    #+#             */
/*   Updated: 2019/10/08 19:06:48 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** -------------------------- External Headers ---------------------------------
*/

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
# include <assert.h>
# include <limits.h>
# include <float.h>
# include <stdint.h>

/*
** --------------------------- Macros \ Static ---------------------------------
*/

# define MAX_LINT 9223372036854775807
# define TRUE 1
# define FALSE 0
# define BUFF_SIZE 64

/*
** ft_printf
*/

# define FLAGS			"0#-+ "
# define N_SPECS		17
# define SPECS			"%cCspdDiouxXfFegGbrk"
# define PF_BUFF		655
# define FLOAT_BUFF		6000

/*
** ------------------------- Structures Definition -----------------------------
*/

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

/*
** ft_printf
*/

/*
** | 1 bit for sign | 15 bit for exponent | 64 bit for mantis |
*/

typedef struct			s_ufloat
{
	uint64_t			mant : 64;
	unsigned int		expo : 15;
	unsigned int		sign : 1;
}						t_ufloat;

typedef union			u_float
{
	long double			value;
	t_ufloat			number;
}						t_float;

typedef struct			s_fstring
{
	int					int_numb[FLOAT_BUFF + 1];
	int					div_numb[FLOAT_BUFF + 1];
	int					int_len;
	char				*digit_str;
	char				*mant_str;
	int					exp;
}						t_fstring;

/*
** Struct with va_list variables for '$' option
*/

typedef struct			s_arg
{
	va_list				n_arg;
	va_list				d_wp;
	va_list				d_arg;
}						t_arg;

/*
** Struct with buffer, result str, etc
*/

typedef struct			s_res
{
	int					fd;
	char				*res;
	int					eol_c;
	char				*p_tmp;
	char				*p_perc;
	char				*end;
	char				buf[PF_BUFF];
	int					len;
	int					percent_treated;
}						t_res;

/*
** Struct with specifier and flags for each percent treatment
*/

typedef struct			s_ftptf
{
	int					percent;
	int					octo;
	int					zero;
	int					minus;
	int					minus_val;
	int					nan;
	int					plus;
	int					spacer;
	int					l;
	int					ll;
	int					l_;
	int					h;
	int					hh;
	char				spec;
	int					base;
	int					width;
	int					dot;
	int					precision;
	int					arg_zero;
	int					dollar[3];
	int					dollar_1_wr;
	int					dollar_2_wr;
	char				sign;
}						t_ftptf;

/*
** Struct for choose the function according to specifier
*/

typedef void			(*t_spec_func)(t_arg*, t_res*, t_ftptf*);

typedef struct			s_type
{
	char				ch;
	t_spec_func			somefunc;
}						t_type;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

void					*ft_memset (void *dest, int c, size_t n);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dest, const void *source, size_t n);
void					*ft_memccpy(void *dest, const void *source, int ch,\
																	size_t n);
void					*ft_memmove (void *destination, const void *source,\
																	size_t n);
void					*ft_memchr (const void *arr, int c, size_t n);
int						ft_memcmp(const void *memptr1, const void *memptr2,\
																	size_t n);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *str);
char					*ft_strcpy(char *destptr, const char *srcptr);
char					*ft_strncpy(char *destptr, const char *srcptr, \
																	size_t n);
char					*ft_strcat (char *dest, const char *app);
char					*ft_strncat (char *dest, const char *app, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t n);
char					*ft_strchr(const char *str, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *str_a, const char *str_b);
char					*ft_strnstr(const char *str_b, const char *str_a,\
																	size_t n);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, \
												char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start, \
																	size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					*ft_itoa(int n);
char					**ft_strsplit(char const *s, char c);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, \
												void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_lstaddend(t_list **list, t_list *new);
size_t					ft_list_size(t_list *begin_list);
char					*ft_strsepcut(char const *s, char c);
void					ft_list_clear(t_list **begin_list);
size_t					ft_word_count(char const *s, char c);
void					ft_free_tdarr(char **str);
void					*ft_node_del(t_list **begin_list, t_list *node, \
																	void *n);
void					ft_free_two_dem_str(char **str);
int						ft_str_is_int(char *str);
int						ft_get_next_line(const int fd, char **line);

/*
** ft_printf
*/

int						ft_abs(int i);
int						ft_printf(const char *format, ...);
int						ft_dprintf(int fd, const char *format, ...);
int						ft_parsing(t_arg *ap_t, t_ftptf *tmp_t, t_res *buf_t);
char					*ft_parse_flags(char *p, t_ftptf *ptf_str, t_arg *ap_t);
char					*ft_parse_spec(char *p, t_ftptf *ptf_str);
int						ft_find_in_def(char *define_line, char *p);
char					*ft_strpcpy(char *start, char *end);
void					ft_percent_treat(t_arg *ap_t, t_res *buf_t);
void					ft_choose_func(t_arg *ap_t, t_res *buf_t, \
							t_ftptf *tmp_t);
void					ft_error_exit(char *str, t_res *buf_t);
char					*ft_dollar_treat(char *p, t_ftptf *tmp_t, t_arg *ap_t);
int						ft_isbigger(int a, int b);
char					*ft_strcpy_dptp(char *dst, char *src, char *end);
char					*ft_i64toa_base(long long int n, int base, int l_size);
char					*ft_u64toa_base(unsigned long long int n, int base, \
							int l_size);
char					*ft_width_treat(int len, char *val, t_ftptf tmp_t);
void					*ft_dollar_arg(int n, t_arg *ap_t);
char					*ft_num_to_str(void *val, t_ftptf tmp_t, int l_size);
char					*ft_precision_treat(char *tmp, t_ftptf tmp_t);
int						ft_bzero_buf_n_set_pointers(t_res *buf_t, \
							const char *format);
int						ft_final_print_n_free_rt_len(int fd, t_res *buf_t);
void					ft_add_specials(char *res, t_ftptf tmp_t);
char					*ft_exception_treat(t_float res, t_ftptf *tmp_t);
char					*ft_count_float(t_float res, t_ftptf tmp_t);
t_fstring				*ft_get_integer(t_fstring *numb);
t_fstring				*ft_get_divisional(t_fstring *numb);
char					*ft_round_float(t_fstring *numb, t_ftptf tmp_t);
char					*ft_integer_to_str(t_fstring *numb);
t_fstring				*ft_add_dig_to_int(t_fstring *numb);
char					*ft_width_n_precision(char *p, t_ftptf *tmp_t, \
							t_arg *ap_t);
t_fstring				*ft_add_float_to_str(t_fstring *numb, t_ftptf tmp_t);
void					ft_put_div_by_one(int div[]);

/*
** ft_printf() / Buffer management functions
*/

void					ft_buff_print_n_len(int fd, t_res *buf_t, char *src);
void					ft_buff_free(t_res *buf_t);
void					ft_buff_print_free(t_res *buf_t);
void					ft_buff_finded_percent(t_res *buf_t);
void					ft_buff_treated_percent(t_res *buf_t);
void					ft_buff_no_percent(t_res *buf_t);
void					ft_c(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t);
void					ft_s(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t);
void					ft_p(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t);
void					ft_di(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t);
void					ft_o(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t);
void					ft_u(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t);
void					ft_x(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t);
void					ft_f(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t);
void					ft_b(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t);

#endif
