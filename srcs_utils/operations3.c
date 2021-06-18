# include "../header.h"

void	rra(t_circl *nil[])
{
	t_circl		*tmp0;
	t_circl		*tmp1;
	t_circl		*tmp2;
	t_circl		*tmp3;

	if (nil[A]->size < 2)
		return ;
	tmp0 = nil[A]->prev->prev;
	tmp1 = nil[A]->prev;
	tmp2 = nil[A];
	tmp3 = nil[A]->next;
	tmp0->next = tmp2;
	tmp2->prev = tmp0;
	tmp2->next = tmp1;
	tmp1->prev = tmp2;
	tmp1->next = tmp3;
	tmp3->prev = tmp1;
}

void	rrb(t_circl *nil[])
{
	t_circl		*tmp0;
	t_circl		*tmp1;
	t_circl		*tmp2;
	t_circl		*tmp3;

	if (nil[B]->size < 2)
		return ;
	tmp0 = nil[B]->prev->prev;
	tmp1 = nil[B]->prev;
	tmp2 = nil[B];
	tmp3 = nil[B]->next;
	tmp0->next = tmp2;
	tmp2->prev = tmp0;
	tmp2->next = tmp1;
	tmp1->prev = tmp2;
	tmp1->next = tmp3;
	tmp3->prev = tmp1;
}

void	rrr(t_circl *nil[])
{
	rra(nil);
	rrb(nil);
}
