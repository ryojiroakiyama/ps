# include "../header.h"

void	optimize_rra(t_oplist *now)
{
	if (now->prev->op == RA)
	{
		now->prev->op = -1;
		now->op = -1;
	}
	else if (now->next->op == RRB)
	{
		now->op = -1;
		now->next->op = RRR;
	}
}

void	optimize_rrb(t_oplist *now)
{
	if (now->prev->op == RB)
	{
		now->prev->op = -1;
		now->op = -1;
	}
	else if (now->next->op == RRA)
	{
		now->op = -1;
		now->next->op = RRR;
	}
}

void	optimize_rrr(t_oplist *now)
{
	if (now->prev->op == -1 && now->prev->prev->op == RR)
		now->op = -1;
}
