/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:15:22 by acanadil          #+#    #+#             */
/*   Updated: 2026/03/02 11:59:16 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static void	print_sol(t_stack *stack, t_flags *flags)
{
	if (is_sorted(stack -> stacka))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_flaclear(&flags);
	free_stack(&stack);
}

static t_stack	*asign(t_list *a)
{
	t_stack	*stack;
	t_bench	*bench;

	stack = ft_calloc(sizeof (t_stack), 1);
	bench = ft_calloc(sizeof (t_bench), 1);
	stack -> calc = bench;
	stack -> stacka = a;
	return (stack);
}

int	main(int argv, char **args)
{
	t_list	*stacka;
	t_stack	*stack;
	t_flags	*flags;
	char	*s;

	flags = NULL;
	if (argv < 1)
		return (0);
	args++;
	stacka = parser(args, &flags, 0);
	if (!stacka)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack = asign(stacka);
	s = get_next_line(0);
	while (s)
	{
		makemove(&stack, s);
		s = get_next_line(0);
	}
	print_sol(stack, flags);
	return (0);
}
