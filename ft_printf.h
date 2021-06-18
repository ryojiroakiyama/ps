#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define INIT -1
# define INVALID -2
# define DOT_ONLY -3

enum e_flag
{
	NON,
	HYPHEN,
	ZERO,
	FLAG_NUM
};

enum e_spec
{
	SPEC_C,
	SPEC_S,
	SPEC_P,
	SPEC_D,
	SPEC_I,
	SPEC_U,
	SPEC_SX,
	SPEC_LX,
	SPEC_PER,
	SPEC_NUM
};

typedef struct s_list
{
	int		flag;
	int		width;
	int		prec;
	int		spec;
	int		body;
	int		zero;
	int		blank;
	char	*prefix;
	char	*basestr;
	int		base;
	int		putnum;
}	t_list;

void	ft_lstnew_init(t_list *t);
int		ft_isspec(char c);
int		cnt_digit(unsigned long long n, unsigned long long div);
int		ft_strnlen(const char *s, int n);
void	setlst_various(t_list *lst, unsigned long long nb);
void	put_flag_h(t_list *lst, char c);
void	put_flag_z(t_list *lst, char c);
void	put_flag_n(t_list *lst, char c);
void	route_num2(unsigned long long nb, t_list *lst,
			void (*g[])(t_list *, char));
void	route_c(t_list *lst, va_list *ap, void (*g[])(t_list *, char));
void	route_s(t_list *lst, va_list *ap, void (*g[])(t_list *, char));
void	route_num1(t_list *lst, va_list *ap, void (*g[])(t_list *, char));
void	put_arg(t_list *lst, va_list *ap);
void	setlst_width(t_list *lst, const char *fmt, size_t *i, va_list *ap);
void	setlst_prec(t_list *lst, const char *fmt, size_t *i, va_list *ap);
int		per_section(const char *fmt, size_t *i, va_list *ap);
int		ft_printf(const char *fmt, ...);

#endif