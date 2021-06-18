# include "../header.h"

void	ft_oplost(t_oplist *lost)
{
	t_oplist	*bef;
	t_oplist	*aft;

	bef = lost->prev;
	aft = lost->next;
	bef->next = aft;
	aft->prev = bef;
}

void	ft_opadd(t_oplist *before, t_oplist *new)
{
	t_oplist	*tmp1;
	t_oplist	*tmp2;

	tmp1 = before;
	tmp2 = before->next;
	tmp1->next = new;
	new->prev = tmp1;
	new->next = tmp2;
	tmp2->prev = new;
}

t_oplist	*ft_opnew(int nb, t_circl *nil[], t_oplist *nop)
{
	t_oplist	*tmp;

	tmp = (t_oplist *)malloc(sizeof(t_oplist));
	if (!tmp)
		ft_exit(nil, nop, 1);
	tmp->op = nb;
	tmp->prev = tmp;
	tmp->next = tmp;
	return (tmp);
}
