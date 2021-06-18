# include "../header.h"

void	optimize_sa(t_oplist *now)
{
	if (now->prev->op == SA)
	{
		now->prev->op = -1;
		now->op = -1;
	}
	if (now->prev->op == SB)
	{
		now->prev->op = -1;
		now->op = SS;
	}
}

void	optimize_sb(t_oplist *now)
{
	if (now->prev->op == SB)
	{
		now->prev->op = -1;
		now->op = -1;
	}
	if (now->prev->op == SA)
	{
		now->prev->op = -1;
		now->op = SS;
	}
}

void	optimize_ss(t_oplist *now)
{
	if (now->prev->op == -1 && now->prev->prev->op == SS)
	{
		now->prev->prev->op = -1;
		now->op = -1;
	}
}

void	optimize(t_oplist *nop)
{
	t_oplist	*move;
	void		(*f[OP_NUM])(t_oplist *);

	f[SA] = optimize_sa;
	f[SB] = optimize_sb;
	f[SS] = optimize_ss;
	f[PA] = optimize_pa;
	f[PB] = optimize_pb;
	f[RA] = optimize_ra;
	f[RB] = optimize_rb;
	f[RR] = optimize_rr;
	f[RRA] = optimize_rra;
	f[RRB] = optimize_rrb;
	f[RRR] = optimize_rrr;
	move = nop->next;
	while (move != nop)
	{
		f[move->op](move);
		move = move->next;
	}
}
