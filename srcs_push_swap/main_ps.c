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
	}
}

void	handle_stackb(t_circl *nil[], t_oplist *nop)
{
	int		median;
	int		clsize;

	while (nil[B]->size > 5)
	{
		clsize = nil[B]->size;
		median = nil[B]->class - (nil[B]->size / 2);
		while (clsize--)
		{
			if (nil[B]->next->num > median)
				px(nil, A, nop);
			else if (nil[B]->next->num == nil[A]->num)
				px(nil, A, nop);
			else
				rx(nil, B, nop);
			sx_and_rx(nil, nop);
		}
		nil[B]->class = median;
	}
	sort_under5v(nil, B, nop);
}

void	sort_roop(t_circl *nil[], t_oplist *nop)
{
	int		class;
	int		prenum;

	handle_stackb(nil, nop);
	while (nil[A]->next->num != 1)
	{
		class = nil[A]->next->class;
		while (nil[A]->next->class == class)
		{
			prenum = nil[A]->num;
			while (detect(nil))
				sx_and_rx(nil, nop);
			if (prenum == nil[A]->num)
				px(nil, B, nop);
		}
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
