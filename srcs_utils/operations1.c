# include "../header.h"

void	sa(t_circl *nil[])
{
	t_circl		*tmp1;
	t_circl		*tmp2;
	t_circl		*tmp3;

	if (nil[A]->size < 2)
		return ;
	tmp1 = nil[A]->next;
	tmp2 = nil[A]->next->next;
	tmp3 = nil[A]->next->next->next;
	nil[A]->next = tmp2;
	tmp2->prev = nil[A];
	tmp2->next = tmp1;
	tmp1->prev = tmp2;
	tmp1->next = tmp3;
	tmp3->prev = tmp1;
}

void	sb(t_circl *nil[])
{
	t_circl		*tmp1;
	t_circl		*tmp2;
	t_circl		*tmp3;

	if (nil[B]->size < 2)
		return ;
	tmp1 = nil[B]->next;
	tmp2 = nil[B]->next->next;
	tmp3 = nil[B]->next->next->next;
	nil[B]->next = tmp2;
	tmp2->prev = nil[B];
	tmp2->next = tmp1;
	tmp1->prev = tmp2;
	tmp1->next = tmp3;
	tmp3->prev = tmp1;
}

void	ss(t_circl *nil[])
{
	sa(nil);
	sb(nil);
}
