# include "../header.h"

int	to_back_stacka(t_circl *nil[], t_oplist *nop)
{
//	if (nil[A]->size < 2)
//		return ;
	if (nil[A]->num == nil[B]->prev->num && nil[B]->size > 1)
		rrx(nil, B, nop);
	if (nil[A]->num == nil[B]->next->num)
		px(nil, A, nop);
	if (nil[A]->num == nil[A]->next->next->num)
		sx(nil, A, nop);
	if (nil[A]->num == nil[A]->next->num)
	{
		rx(nil, A, nop);
		nil[A]->num++;
		return (1);
	}
	return (0);
}

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

int	get_rx_or_rrx(t_circl *nil[], int i, int dst)
{
	int		posit;
	t_circl *move;

	posit = 1;
	move = nil[i]->next;
	while (move->next->num != dst)
	{
		if (move == nil[i])
			return (-1);
		posit++;
		move = move->next;
	}
	if (posit <= nil[i]->size / 2)
		return (0);
	else
		return (1);
}

void	rotate_dst(t_circl *nil[], int i, int dst, t_oplist *nop)
{
	if (get_rx_or_rrx(nil, i, dst) == 0)
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

void	sort_5v(t_circl *nil[], int i, t_oplist *nop)
{
	int		push_num;
	int		presize;

	presize = nil[i]->size;
	if (is_sorted(nil, i))
		return ;
	push_num = get_minnum(nil, i);
	while (nil[i]->size > 3)
	{
		rotate_dst(nil, i, push_num, nop);
		px(nil, (i - 1) * -1 , nop);
		if (i == B)
			to_back_stacka(nil, nop);
		push_num++;
	}
	sort_3v(nil, i, nop);
	while (nil[i]->size < presize && i == A)
		px(nil, i, nop);
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
	else if (nil[i]->size <= 5)
		sort_5v(nil, i, nop);
	while (nil[B]->size)
	{
		px(nil, A, nop);
		to_back_stacka(nil, nop);
	}
}
