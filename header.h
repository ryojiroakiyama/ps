#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"//

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include "./gnl/get_next_line.h"

enum e_stack
{
	A,
	B,
	STACK_NUM
};

enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_NUM
};

typedef struct s_circl
{
	int				value;
	int				size;
	int				num;
	int				class;
	struct s_circl	*next;
	struct s_circl	*prev;
}	t_circl;

typedef struct s_oplist
{
	int				op;
	struct s_oplist	*next;
	struct s_oplist	*prev;
}	t_oplist;

void	put_cl(t_circl *nil[], char *comment);

void	optimize_sa(t_oplist *now);
void	optimize_sb(t_oplist *now);
void	optimize_ss(t_oplist *now);
void	optimize(t_oplist *nop);
void	optimize_pa(t_oplist *now);
void	optimize_pb(t_oplist *now);
void	optimize_ra(t_oplist *now);
void	optimize_rb(t_oplist *now);
void	optimize_rr(t_oplist *now);
void	optimize_rra(t_oplist *now);
void	optimize_rrb(t_oplist *now);
void	optimize_rrr(t_oplist *now);
void	put_op(t_oplist *nop);
int		sx_and_rx(t_circl *nil[], t_oplist *nop, int i);
int		get_minnum(t_circl	*nil[], int i);
void	rx_or_rrx(t_circl *nil[], int i, int dst, t_oplist *nop);
void	sort_3v(t_circl *nil[], int i, t_oplist *nop);
void	sort_5v(t_circl *nil[], int i, t_oplist *nop);
void	sort_under5v(t_circl *nil[], int i, t_oplist *nop);
void	first_action(t_circl *nil[], t_oplist *nop);
void	handle_stackb(t_circl *nil[], t_oplist *nop);
void	sort_roop(t_circl *nil[], t_oplist *nop);
void	sx(t_circl *nil[], int i, t_oplist *nop);
void	px(t_circl *nil[], int i, t_oplist *nop);
void	rx(t_circl *nil[], int i, t_oplist *nop);
void	rrx(t_circl *nil[], int i, t_oplist *nop);
int		ft_atoi_ps(const char *str, t_circl *nil[], t_oplist *nop);
int		ft_strcmp(char *s1, char *s2);
void	ft_cladd(t_circl *before, t_circl *new);
void	ft_cllost(t_circl *lost);
t_circl	*ft_clnew(int nb, t_circl *nil[], t_oplist *nop);
void	make_stacka(t_circl *nil[], t_oplist *nop, int ac, char *av[]);
void	ft_oplost(t_oplist *lost);
void	ft_opadd(t_oplist *before, t_oplist *new);
t_oplist	*ft_opnew(int nb, t_circl *nil[], t_oplist *nop);
int		is_sorted(t_circl *nil[], int i);
void	ft_clclear(t_circl *nil[]);
void	ft_opclear(t_oplist *nop);
void	ft_exit(t_circl *nil[], t_oplist *nop, int result);
void	sa(t_circl *nil[]);
void	sb(t_circl *nil[]);
void	ss(t_circl *nil[]);
void	pa(t_circl *nil[]);
void	pb(t_circl *nil[]);
void	ra(t_circl *nil[]);
void	rb(t_circl *nil[]);
void	rr(t_circl *nil[]);
void	rra(t_circl *nil[]);
void	rrb(t_circl *nil[]);
void	rrr(t_circl *nil[]);

int		find_op(char *line);
void	make_oplist(t_circl *nil[], t_oplist *nop);
void	execute_op(t_circl *nil[], t_oplist *nop);

#endif