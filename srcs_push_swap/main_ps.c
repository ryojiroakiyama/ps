# include "../header.h"

void	first_action(t_circl *nil[], t_oplist *nop)
{
	int		median;
	int		clsize;

	sort_under5v(nil, A, nop);
	if (is_sorted(nil, A))
		ft_exit(nil, nop, 0);
	median = nil[A]->size / 2;
	clsize = nil[A]->size;
	while (clsize--)
	{
		if (nil[A]->next->num <= median)
			px(nil, B, nop);
		else
			rx(nil, A, nop);
		if (nil[B]->next->num == 1)
			rx(nil, B, nop);
	}
	to_back_stacka(nil, nop);
}

int	is_over_median(t_circl *nil[], int i, int median)
{
	t_circl *move;

	move = nil[i]->next;
	while (move != nil[i])
	{
		if (move->num > median)
			return (1);
		move = move->next;
	}
	return (0);
}

void	handle_stackb(t_circl *nil[], t_oplist *nop)
{
	int		median;
	int		cnt;

	cnt = 0;
	while (nil[B]->size > 5)
	{
		median = nil[B]->class - (nil[B]->size / 2);
		while (is_over_median(nil, B, median))
		{
			if (nil[B]->next->num > median)
				px(nil, A, nop);
			else if (nil[B]->next->num == nil[A]->num)
				px(nil, A, nop);
			else
				rx(nil, B, nop);
			while (to_back_stacka(nil, nop))
				cnt++;
		}
		nil[B]->class = median;
	}
	sort_under5v(nil, B, nop);
}

void	sort_roop(t_circl *nil[], t_oplist *nop)
{
	int		class;
	int		cnt;

	handle_stackb(nil, nop);
	while (nil[A]->next->num != 1)
	{
		class = nil[A]->next->class;
		while (nil[A]->next->class == class)
		{
			cnt = 0;
			while (to_back_stacka(nil, nop))
				cnt++;
			if (cnt == 0)
				px(nil, B, nop);
			if (nil[B]->next->num == nil[A]->num + 1)
				rx(nil, B, nop);
		}
		while (to_back_stacka(nil, nop))
			cnt++;
		handle_stackb(nil, nop);
	}
}

int main(int ac, char *av[])
{
	t_circl		*nil[STACK_NUM];
	t_oplist	*nop;

	if (ac == 1)
		return (0);
	nil[A] = NULL;
	nil[B] = NULL;
	nop = NULL;
	nil[A] = ft_clnew(0, nil, nop);
	nil[B] = ft_clnew(0, nil, nop);
	nop = ft_opnew(-1, nil, nop);
	make_stacka(nil, nop, ac, av);
	nil[A]->size = ac - 1;
	first_action(nil, nop);
	sort_roop(nil, nop);
	optimize(nop);
	ft_exit(nil, nop, 0);
	return (0);
}
