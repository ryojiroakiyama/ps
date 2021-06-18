# include "../header.h"

int	sx_and_rx(t_circl *nil[], t_oplist *nop, int i)
{
	if (nil[i]->size < 2)
		return (1);
	if (nil[i]->prev->num + 1 == nil[i]->next->next->num)
		sx(nil, i, nop);
	if (nil[i]->prev->num + 1 == nil[i]->next->num)
	{
		rx(nil, i, nop);
		return (0);
	}
	else
		return (1);
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

void	sort_5v(t_circl *nil[], int i, t_oplist *nop)
{
	int		opp;
	int		min;
	int		presize;

	if (is_sorted(nil, i))
		return ;
	min = get_minnum(nil, i);
	opp = (i - 1) * -1;
	presize = nil[i]->size;
	while (nil[i]->size > 3)
	{
		rx_or_rrx(nil, i, min, nop);
		px(nil, opp, nop);
		min += 1;
	}
	sort_3v(nil, i, nop);
	while (nil[i]->size < presize)
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
	if (i == B)
	{
		while (nil[B]->size)
		{
			px(nil, A, nop);
			rx(nil, A, nop);
		}
	}
}
