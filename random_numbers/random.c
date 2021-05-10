#include <stdlib.h>
#include <stdio.h>

static int	num_in_list(int num, int len, int **list)
{
	int	tmp;

	tmp = 0;
	while (tmp < len)
	{
		if (num == (*list)[tmp])
			return (1);
		tmp++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	*rep;
	int	count;
	int	num;

	if (argc ==  4)
	{
		count = 0;
		rep = (int *)malloc(sizeof(int) * atoi(argv[1]));
		while (count < atoi(argv[1]))
		{
			num = rand() % atoi(argv[3]) + atoi(argv[2]);
			while (num_in_list(num, count, &rep))
				num = rand() % atoi(argv[3]) + atoi(argv[2]);
			rep[count] = num;
			printf("%d ", num);
			count++;
		}
		printf("\n");
	}
	else
		printf("\033[31mError, formato: len min max\033[39m\n");
}
