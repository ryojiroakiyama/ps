# include "../header.h"

int	find_op(char *line)
{
	if (line == NULL)
		return (-1);
	if (*line == '\0')
		return (-2);
	if (ft_strcmp("sa", line) == 0)
		return (SA);
	if (ft_strcmp("sb", line) == 0)
		return (SB);
	if (ft_strcmp("ss", line) == 0)
		return (SS);
	if (ft_strcmp("pa", line) == 0)
		return (PA);
	if (ft_strcmp("pb", line) == 0)
		return (PB);
	if (ft_strcmp("ra", line) == 0)
		return (RA);
	if (ft_strcmp("rb", line) == 0)
		return (RB);
	if (ft_strcmp("rr", line) == 0)
		return (RR);
	if (ft_strcmp("rra", line) == 0)
		return (RRA);
	if (ft_strcmp("rrb", line) == 0)
		return (RRB);
	if (ft_strcmp("rrr", line) == 0)
		return (RRR);
	return (-3);
}

void	make_oplist(t_circl *nil[], t_oplist *nop)
{
	t_oplist	*tmp;
	char		*line;
	int			sign;

	line = NULL;
	while (1)
	{
		sign = get_next_line(0, &line);
		tmp = ft_opnew(find_op(line), nil, nop);
		ft_opadd(nop->prev, tmp);
		free(line);
		line = NULL;
		if (sign != 1 || nop->prev->op < 0)
		{
			if (sign == 0 && nop->prev->op == -2)//have to consider if instruction don't exist or not
			{
				tmp = nop->prev;
				ft_oplost(nop->prev);
				free(tmp);
				break ;
			}
			else
				ft_exit(nil, nop, 1);
		}
	}
}
/*
static	void	tmput_op(int op)//
{
	void		*op_str[OP_NUM];

	op_str[SA] = "sa\n";
	op_str[SB] = "sb\n";
	op_str[SS] = "ss\n";
	op_str[PA] = "pa\n";
	op_str[PB] = "pb\n";
	op_str[RA] = "ra\n";
	op_str[RB] = "rb\n";
	op_str[RR] = "rr\n";
	op_str[RRA] = "rra\n";
	op_str[RRB] = "rrb\n";
	op_str[RRR] = "rrr\n";
	if (SA <= op && op <= RR)
		write(1, op_str[op], 3);
	if (RR < op)
		write(1, op_str[op], 4);
}
*/
void	execute_op(t_circl *nil[], t_oplist *nop)
{
	void		(*f[OP_NUM])(t_circl *nil[]);
	t_oplist	*move;

	f[SA] = sa;
	f[SB] = sb;
	f[SS] = ss;
	f[PA] = pa;
	f[PB] = pb;
	f[RA] = ra;
	f[RB] = rb;
	f[RR] = rr;
	f[RRA] = rra;
	f[RRB] = rrb;
	f[RRR] = rrr;
	move = nop->next;
	while (move != nop)
	{
		f[move->op](nil);
		move = move->next;
	}
}

int main(int ac, char *av[])
{
	t_circl		*nil[STACK_NUM];
	t_oplist	*nop;

	if (ac == 1)
		return (0);
	nil[A] = NULL;
	nil[B] = NULL;
	nop = NULL;
	nil[A] = ft_clnew(0, nil, nop);
	nil[B] = ft_clnew(0, nil, nop);
	nop = ft_opnew(-1, nil, nop);
	make_stacka(nil, nop, ac, av);
	nil[A]->size = ac - 1;
	nil[A]->class = -1;
	make_oplist(nil, nop);
	execute_op(nil, nop);
	if (is_sorted(nil, A))//have to consider about if stack_b is empty or not
		ft_exit(nil, nop, 0);
	else
		write(1, "KO\n", 3);
	return (0);
}
