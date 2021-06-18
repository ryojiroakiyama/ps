# include "../header.h"

void	ft_cladd(t_circl *before, t_circl *new)
{
	t_circl	*tmp1;
	t_circl	*tmp2;

	tmp1 = before;
	tmp2 = before->next;
	tmp1->next = new;
	new->prev = tmp1;
	new->next = tmp2;
	tmp2->prev = new;
}

void	ft_cllost(t_circl *lost)
{
	t_circl	*bef;
	t_circl	*aft;

	bef = lost->prev;
	aft = lost->next;
	bef->next = aft;
	aft->prev = bef;
}

t_circl	*ft_clnew(int nb, t_circl *nil[], t_oplist *nop)
{
	t_circl	*tmp;

	tmp = (t_circl *)malloc(sizeof(t_circl));
	if (!tmp)
		ft_exit(nil, nop, 1);
	tmp->value = nb;
	tmp->size = 0;
	tmp->num = 1;
	tmp->class = 0;
	tmp->prev = tmp;
	tmp->next = tmp;
	return (tmp);
}

void	make_stacka(t_circl *nil[], t_oplist *nop, int ac, char *av[])
{
	t_circl	*tmp;
	t_circl	*move;
	int		i;

	i = 1;
	while (i < ac)
	{
		tmp = ft_clnew(ft_atoi_ps(av[i], nil, nop), nil, nop);
		move = nil[A]->next;
		while (move != nil[A])
		{
			if (move->value == tmp->value)
				ft_exit(nil, nop, 1);
			if (move->value < tmp->value)
				tmp->num++;
			if (move->value > tmp->value)
				move->num++;
			move = move->next;
		}
		ft_cladd(nil[A]->prev, tmp);
		i++;
	}
}
