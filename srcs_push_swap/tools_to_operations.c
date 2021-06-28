#include "../header.h"

void	sx(t_circl *nil[], int i, t_oplist *nop)
{
	t_oplist	*tmpop;

	tmpop = NULL;
	if (i == A)
	{
		sa(nil);
		tmpop = ft_opnew(SA, nil, nop);
	}
	if (i == B)
	{
		sb(nil);
		tmpop = ft_opnew(SB, nil, nop);
	}
	ft_opadd(nop->prev, tmpop);
}

void	px(t_circl *nil[], int i, t_oplist *nop)
{
	t_oplist	*tmpop;

	tmpop = NULL;
	if (i == A)
	{
		pa(nil);
		nil[A]->next->class = nil[B]->class;
		tmpop = ft_opnew(PA, nil, nop);
	}
	if (i == B)
	{
		pb(nil);
		if (nil[B]->next->num > nil[B]->class)
			nil[B]->class = nil[B]->next->num;
		tmpop = ft_opnew(PB, nil, nop);
	}
	ft_opadd(nop->prev, tmpop);
}

void	rx(t_circl *nil[], int i, t_oplist *nop)
{
	t_oplist	*tmpop;

	tmpop = NULL;
	if (i == A)
	{
		ra(nil);
		tmpop = ft_opnew(RA, nil, nop);
	}
	if (i == B)
	{
		rb(nil);
		tmpop = ft_opnew(RB, nil, nop);
	}
	ft_opadd(nop->prev, tmpop);
}

void	rrx(t_circl *nil[], int i, t_oplist *nop)
{
	t_oplist	*tmpop;

	tmpop = NULL;
	if (i == A)
	{
		rra(nil);
		tmpop = ft_opnew(RRA, nil, nop);
	}
	if (i == B)
	{
		rrb(nil);
		tmpop = ft_opnew(RRB, nil, nop);
	}
	ft_opadd(nop->prev, tmpop);
}
