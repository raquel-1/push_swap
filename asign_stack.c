/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asign_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 10:26:44 by acanadil          #+#    #+#             */
/*   Updated: 2026/03/02 11:40:07 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_flags.h"

static int	foun_number(t_list **stacka, t_list *num)
{
	t_list	*aux;

	aux = *stacka;
	while (aux)
	{
		if (aux ->num == num -> num)
			return (1);
		aux = aux -> next;
	}
	return (0);
}

static int	freesear(t_list **stacka, int print)
{
	ft_lstclear(stacka);
	if (print)
		write(2, "Error\n", 6);
	return (0);
}

static int	letercorrect(char **arg, t_list **stacka)
{
	char	*aux;
	char	*num;
	t_list	*number;
	long	i;

	aux = *arg;
	if (!*aux)
		return (1);
	if (*aux == '-')
		aux++;
	while (aux && ft_isdigit(*aux))
		aux++;
	num = ft_substr(*arg, 0, aux - *arg);
	i = ft_atoi_long(num);
	if (i > 2147483647 || -2147483648 > i)
		return (freesear(stacka, 1));
	number = ft_lstnew((int) i);
	if (foun_number(stacka, number))
		return (freesear(stacka, 1));
	if (number)
		ft_lstadd_back(stacka, number);
	else
		ft_lstclear(&number);
	*arg = aux;
	return (1);
}

void	save_numbers(char **arg, t_flags *flags, t_list **stacka)
{
	int		j;
	char	*ptr;
	t_flags	*flag;

	j = 0;
	while (arg[j])
	{
		ptr = arg[j];
		flag = asignflag(flags, j);
		while (*ptr)
		{
			while (*ptr && *ptr == ' ')
				ptr++;
			if (verifflag(flag, &ptr))
				continue ;
			if (!letercorrect(&ptr, stacka))
				return ;
		}
		ft_flaclear(&flag);
		j++;
	}
}
