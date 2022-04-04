/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:28:48 by bordenoy          #+#    #+#             */
/*   Updated: 2022/04/04 14:46:43 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# define BUFF_SIZE 55
# define SIZE_OPT 12

typedef struct s_opt
{
	unsigned int	opt : 5;
	int				largeur;
	int				precision;
	unsigned int	prec;
	unsigned int	taille;
	char			conversion;
}	t_opt;

typedef struct s_gob
{
	t_opt	opt;
	char	*b;
}	t_gob;

typedef struct s_ch
{
	unsigned int	opt : 5;
}	t_ch;

typedef struct s_printf
{
	t_opt	opt;
	void	(*ptf)(va_list ap, t_gob);
}	t_printf;

int					plt(t_opt *opt, int i);
int					ptt(t_opt *opt, t_ch ch, int c, const char *f);
int					pft(t_opt *opt, const char *f, int c);
int					pst(t_opt *opt, va_list ap);
int					prt(t_opt *opt, va_list ap);
long				abss(long i);
t_gob				ft_ar(t_gob opt, unsigned long long b);
void				aff_rest(long long a, t_gob opt);
void				ft_nulls(t_gob opt);
int					largeur(t_gob opt, int a, int b, char pp);
void				ft_nullf(long long m, long double a, t_gob opt);
int					isin(char c, char *str);
void				ft_null(t_gob opt, char *b);
void				ft_rot(int *largeur, int y, int u, t_gob opt);
int					ft_typemoi(long double a);
void				ft_signe(t_gob opt, long double a);
int					ft_nan(long double a, t_gob opt);
void				ft_in(t_gob opt, char *v, int a);
int					ft_printf(const char *format, ...);
size_t				ft_strlen_at(const char *str, size_t a);
char				*ft_itoa(int b);
void				ft_bzero(void *v, size_t n);
void				ft_setbuffer(char *c);
void				ft_add(t_gob opt, char c);
int					ft_putstrlensize(char *c, int y);
int					ft_getsize(char *b, int c);
size_t				ft_strlen(const char *c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
int					end(t_gob opt);
int					ft_atoi(const char *str);
int					par(const char *format, t_opt *opt, va_list ap, int c);
void				ft_putnbr(va_list nbr, t_gob opt);
void				ft_putnbr_unsigned(va_list nbr, t_gob opt);
void				ft_putster(va_list nbr, t_gob opt);
void				ft_putchar(va_list nbr, t_gob opt);
void				ft_pourcentage(t_gob opt);
int					ft_putnbr_base(long long n, char *t, int a, t_gob opt);
int					ft_u_b(unsigned long long n, char *b, int a, t_gob o);
int					ft_ret(long long h, char *c, int a, t_gob opt);
int					ft_retu(unsigned long long h, char *c, int a, t_gob o);
void				ft_putnbr_address(va_list nbr, t_gob opt);
char				opts(t_gob opt, int nb);
int					hexa(t_gob opt, char c, int g, int a);
void				affre(t_gob opt, int a, int b);
void				offre(t_gob opt, int a, int b);
void				ft_floater(long double nbr, t_gob opt);
void				ffre(t_opt opt, int a, int b);
int					or(int a, int b, int g, t_gob opt);
void				ft_arrange(t_gob opt, char format, va_list ap);
t_opt				getopts(const char *str);
int					taille(const char *format, t_opt *opt);
int					ft_size(unsigned int a);
void				ft_fl_base(long long a, char *b, t_gob opt);
int					float_count(long long a);
char				ft_floatzero(t_gob opt);
void				float_optafter(long long a, t_gob opt);
void				ft_getf(va_list ap, t_gob opt);
void				float_opt(long long a, t_gob opt);
void				aff_float(long long a, long long b, t_gob opt);
void				ft_floater(long double hallo, t_gob opt);
void				ft_pour(t_gob opt);
int					moin(t_gob opt, char c);
#endif
