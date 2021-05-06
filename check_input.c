#include "push_swap.h"

int	find_variable(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (count == 0 && !ft_isdigit(str[count])
			&& str[0] != '-' && str[0] != '+')
			return (1);
		else if (count > 0 && !ft_isdigit(str[count]))
			return (1);
		count++;
	}
	return (0);
}

void	check_argument(char *str)
{
	char	*it;
	int	count;
	int	tmp;

	count = 0;
	while (str[count])
	{
		tmp = 0;
		while (str[tmp] == '0' && str[tmp + 1])
			tmp++;
		it = ft_itoa(ft_atoi(str + tmp));
		if (count == 0 && (!ft_isdigit(str[count])
			&& str[count] != '-' && str[count] != '+'))
			ft_error("Error");
		else if (count == 0 && ((str[count] == '-')
			&& ft_strlen(str) <= 1))
			ft_error("Error");
		else if (count != 0 && !ft_isdigit(str[count]))
			ft_error("Error");
		if (str[0] == '+')
			tmp++;
		else if (ft_strncmp(str + tmp, it, ft_strlen(str)) != 0
			&& ft_atoi(str) != 0)
		{
			ft_printf("\033[31mError\033[39m\n");
			exit(0);
		}
		free(it);
		count++;
	}
}

void	check_argv(char *str, t_node **stk)
{
	int	num;

	check_argument(str);
	num = ft_atoi(str);
	stack(num, stk);
}

void	check_variable(char *str, t_node **stk)
{
	char	**split;
	int	num;
	int	ct_y;

	split = ft_split(str, ' ');
	ct_y = 0;
	while (split[ct_y + 1])
		ct_y++;
	while (ct_y >= 0)
	{
		check_argument(split[ct_y]);
		num = ft_atoi(split[ct_y]);
		stack(num, stk);
		free(split[ct_y]);
		ct_y--;
	}
	free(split);
}
