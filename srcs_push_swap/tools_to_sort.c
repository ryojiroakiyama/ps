# include "../header.h"

int	detect(t_circl *nil[])
{
	if (nil[A]->size < 2)
		return (0);
	if (nil[B]->next->num == nil[A]->num)
		return (1);
	if (nil[A]->num == nil[A]->next->next->num)
		return (1);
	if (nil[A]->num == nil[A]->next->num)
		return (1);
	return (0);
}

void	sx_and_rx(t_circl *nil[], t_oplist *nop)
{
//	if (nil[A]->size < 2)
//		return ;
	if (nil[B]->next->num == nil[A]->num)
		px(nil, A, nop);
	if (nil[A]->num == nil[A]->next->next->num)
		sx(nil, A, nop);
	if (nil[A]->num == nil[A]->next->num)
	{
		rx(nil, A, nop);
		nil[A]->num++;
	}
}
/*
int	sx_and_rx(t_circl *nil[], t_oplist *nop, int i)
{
	if (nil[i]->size < 2)
		return (1);
	if (nil[i]->num == nil[i]->next->next->num)
		sx(nil, i, nop);
	if (nil[i]->num == nil[i]->next->num)
	{
		rx(nil, i, nop);
		nil[i]->num++;
		return (0);
	}
	else
		return (1);
}
*/
int	get_minnum(t_circl	*nil[], int i)
{
	int		 min;
	t_circl	*tmp;

	min = nil[i]->next->num;
	tmp = nil[i]->next;
	while (tmp != nil[i])
	{
		if (min > tmp->num)
			min = tmp->num;
		tmp = tmp->next;
	}
	return (min);
}

void	rx_or_rrx(t_circl *nil[], int i, int dst, t_oplist *nop)
{
	int		posit;
	t_circl *tmp;

	posit = 1;
	tmp = nil[i]->next;
	while (tmp->next->num != dst)
	{
		posit++;
		tmp = tmp->next;
	}
	if (posit <= nil[i]->size / 2)
	{
		while (nil[i]->next->num != dst)
			rx(nil, i, nop);
	}
	else
	{
		while (nil[i]->next->num != dst)
			rrx(nil, i, nop);
	}
}

void	sort_3v(t_circl *nil[], int i, t_oplist *nop)
{
	t_circl	*tmp1;
	t_circl	*tmp2;
	t_circl	*tmp3;

	tmp1 = nil[i]->next;
	tmp2 = nil[i]->next->next;
	tmp3 = nil[i]->next->next->next;
	if (tmp1->value < tmp2->value && tmp2->value < tmp3->value)
		return ;
	else if (tmp3->value < tmp1->value && tmp1->value < tmp2->value)
	{
		rrx(nil, i, nop);
		sort_3v(nil, i, nop);
	}
	else if (tmp2->value < tmp3->value && tmp3->value < tmp1->value)
	{
		rx(nil, i, nop);
		sort_3v(nil, i, nop);
	}
	else
	{
		sx(nil, i, nop);
		sort_3v(nil, i, nop);
	}
}

void	sort_5v_B(t_circl *nil[], t_oplist *nop)
{
	int		push_num;
	int		presize;

	presize = nil[B]->size;
	if (is_sorted(nil, B))
		return ;
	push_num = get_minnum(nil, B);
	while (nil[B]->size > 3)
	{
		rx_or_rrx(nil, B, push_num, nop);
		px(nil, A, nop);
//		sx_and_rx(nil, nop, A);
		sx_and_rx(nil, nop);
		push_num++;
	}
	sort_3v(nil, B, nop);
}

void	sort_5v_A(t_circl *nil[], t_oplist *nop)
{
	int		push_num;
	int		presize;

	presize = nil[A]->size;
	if (is_sorted(nil, A))
		return ;
	push_num = get_minnum(nil, A);
	while (nil[A]->size > 3)
	{
		rx_or_rrx(nil, A, push_num, nop);
		px(nil, B, nop);
		push_num++;
	}
	sort_3v(nil, A, nop);
	while (nil[A]->size < presize)
		px(nil, A, nop);
}

void	sort_under5v(t_circl *nil[], int i, t_oplist *nop)
{
	if (nil[i]->size == 0)
		return ;
	if (nil[i]->size == 2)
	{
		if (nil[i]->next->value > nil[i]->next->next->value)
			sx(nil, i, nop);
	}
	else if (nil[i]->size == 3)
		sort_3v(nil, i, nop);
	else if (nil[i]->size <= 5 && i == A)
		sort_5v_A(nil, nop);
	else if (nil[i]->size <= 5 && i == B)
		sort_5v_B(nil, nop);
	while (nil[B]->size)
	{
		px(nil, A, nop);
//		sx_and_rx(nil, nop, A);
		sx_and_rx(nil, nop);
	}
}
