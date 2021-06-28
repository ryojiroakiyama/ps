#include "../header.h"

static	int	conv_to_int(const char *str, int sign
							, t_circl *nil[], t_oplist *nop)
{
	int	nb;
	int	tmp_nb;
	int	ov_div;
	int	ov_mod;

	ov_div = INT_MAX / 10;
	ov_mod = INT_MAX % 10;
	nb = 0;
	while ('0' <= *str && *str <= '9')
	{
		tmp_nb = *str - '0';
		if (sign == 1 && (ov_div < nb
				|| (nb == ov_div && ov_mod < tmp_nb)))
			ft_exit(nil, nop, 1);
		else if (sign == -1 && (ov_div < nb
				|| (nb == ov_div && ov_mod + 1 < tmp_nb)))
			ft_exit(nil, nop, 1);
		nb = nb * 10 + tmp_nb;
		str++;
	}
	if (*str != '\0')
		ft_exit(nil, nop, 1);
	if (sign == -1)
		return (-nb);
	return (nb);
}

int	ft_atoi_ps(const char *str, t_circl *nil[], t_oplist *nop)
{
	int	sign;

	if (str == NULL)
		ft_exit(nil, nop, 1);
	sign = 1;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str < '0' || '9' < *str)
		ft_exit(nil, nop, 1);
	return (conv_to_int(str, sign, nil, nop));
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] > s2[i])
			return (1);
		if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}
