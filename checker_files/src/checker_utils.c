/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 09:36:13 by guferrei          #+#    #+#             */
/*   Updated: 2021/10/05 13:52:23 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	is_number(const char *nbr)
{
	while (*nbr)
	{
		if (*nbr == '-' || *nbr == '+')
			nbr++;
		if (!ft_isdigit(*nbr))
			return (0);
		nbr++;
	}
	return (1);
}

int	is_duplicated(int stack[], int index, int x)
{
	while (index >= 0)
	{
		if (stack[index] == x)
			return (0);
		index--;
	}
	return (1);
}

int	is_sorted(int a[], int sizea)
{
	sizea--;
	while ((sizea - 1) >= 0)
	{
		if (a[sizea] < a[sizea - 1])
			sizea--;
		else
			return (0);
	}
	return (1);
}

int	make_stack(char *argv[], int stack[], int argc)
{
	int	x;
	int	y;

	x = 0;
	y = argc - 1;
	while (x < y)
	{
		stack[x] = ft_stoi(argv[(y - x)]);
		if (!is_duplicated(stack, (x - 1), stack[x])
			|| !is_number(argv[(y - x)]) || (stack[x] == 0
				&& ft_strncmp(argv[(y - x)], "0", 1)))
		{
			write(2, "Error\n", 7);
			return (-1);
		}
		x++;
	}
	return (x);
}
