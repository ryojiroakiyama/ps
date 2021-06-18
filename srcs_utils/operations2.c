# include "../header.h"

void	pa(t_circl *nil[])
{
	t_circl		*tmp;

	if (nil[B]->next == nil[B])
		return ;
	tmp = nil[B]->next;
	ft_cllost(nil[B]->next);
	ft_cladd(nil[A], tmp);
	nil[A]->size++;
	nil[B]->size--;
}

void	pb(t_circl *nil[])
{
	t_circl		*tmp;

	if (nil[A]->next == nil[A])
		return ;
	tmp = nil[A]->next;
	ft_cllost(nil[A]->next);
	ft_cladd(nil[B], tmp);
	nil[B]->size++;
	nil[A]->size--;
}

void	ra(t_circl *nil[])
{
	t_circl		*tmp0;
	t_circl		*tmp1;
	t_circl		*tmp2;
	t_circl		*tmp3;

	if (nil[A]->size < 2)
		return ;
	tmp0 = nil[A]->prev;
	tmp1 = nil[A];
	tmp2 = nil[A]->next;
	tmp3 = nil[A]->next->next;
	tmp0->next = tmp2;
	tmp2->prev = tmp0;
	tmp2->next = tmp1;
	tmp1->prev = tmp2;
	tmp1->next = tmp3;
	tmp3->prev = tmp1;
}

void	rb(t_circl *nil[])
{
	t_circl		*tmp0;
	t_circl		*tmp1;
	t_circl		*tmp2;
	t_circl		*tmp3;

	if (nil[B]->size < 2)
		return ;
	tmp0 = nil[B]->prev;
	tmp1 = nil[B];
	tmp2 = nil[B]->next;
	tmp3 = nil[B]->next->next;
	tmp0->next = tmp2;
	tmp2->prev = tmp0;
	tmp2->next = tmp1;
	tmp1->prev = tmp2;
	tmp1->next = tmp3;
	tmp3->prev = tmp1;
}

void	rr(t_circl *nil[])
{
	ra(nil);
	rb(nil);
}
