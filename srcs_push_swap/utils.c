#include "../header.h"

int	is_under_median(t_circl *nil[], int i, int median)
{
	t_circl	*move;

	move = nil[i]->next;
	while (move != nil[i])
	{
		if (move->num <= median)
			return (1);
		move = move->next;
	}
	return (0);
}

int	is_over_median(t_circl *nil[], int i, int median)
{
	t_circl	*move;

	move = nil[i]->next;
	while (move != nil[i])
	{
		if (move->num > median)
			return (1);
		move = move->next;
	}
	return (0);
}

int	get_minnum(t_circl	*nil[], int i)
{
	int		min;
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
	t_circl	*move;

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
