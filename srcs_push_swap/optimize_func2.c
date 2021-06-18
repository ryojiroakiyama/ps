# include "../header.h"

void	optimize_pa(t_oplist *now)
{
	if (now->prev->op == PB)
	{
		now->prev->op = -1;
		now->op = -1;
	}
}

void	optimize_pb(t_oplist *now)
{
	if (now->prev->op == PA)
	{
		now->prev->op = -1;
		now->op = -1;
	}
}

void	optimize_ra(t_oplist *now)
{
	if (now->prev->op == RRA)
	{
		now->prev->op = -1;
		now->op = -1;
	}
	else if (now->next->op == RB)
	{
		now->op = -1;
		now->next->op = RR;
	}
}

void	optimize_rb(t_oplist *now)
{
	if (now->prev->op == RRB)
	{
		now->prev->op = -1;
		now->op = -1;
	}
	else if (now->next->op == RA)
	{
		now->op = -1;
		now->next->op = RR;
	}
}

void	optimize_rr(t_oplist *now)
{
	if (now->prev->op == -1 && now->prev->prev->op == RRR)
		now->op = -1;
}
