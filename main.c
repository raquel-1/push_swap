/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:36:03 by raqroca-          #+#    #+#             */
/*   Updated: 2026/03/04 12:29:15 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	found_flag(t_flags *flag, int pos)
{
	t_flags	*aux;

	aux = flag;
	while (aux)
	{
		if (aux -> num == pos)
			return (1);
		aux = aux -> next;
	}
	return (0);
}

static void	asign_bench(t_stack *sta, char *l, char *s, float d)
{
	sta -> calc -> disorder = d;
	sta -> calc -> flag = l;
	sta -> calc -> strategy = s;
}

static void	execute(t_stack *sta, t_flags *flags)
{
	float	d;

	d = disorder(sta -> stacka);
	if (found_flag(flags, 1))
	{
		asign_bench(sta, "Simple", "O(n^2)", d);
		simple(&sta, 1);
	}
	else if (found_flag(flags, 2))
	{
		asign_bench(sta, "Medium", "O(n√n)", d);
		medium(&sta, 1);
	}
	else if (found_flag(flags, 3))
	{
		asign_bench(sta, "Complex", "O(n log n)", d);
		complex(&sta, 1);
	}
	else
	{
		asign_bench(sta, "Adaptive", sel_strat(d), d);
		adaptiv(&sta, 1);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_stack	*stack;
	t_flags	*flags;

	flags = NULL;
	if (argc <= 1)
		return (0);
	argv++;
	stacka = parser(argv, &flags, 2, 0);
	if (!stacka)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack = asign(stacka);
	execute(stack, flags);
	if (found_flag(flags, 0))
		print_bench(stack -> calc);
	ft_flaclear(&flags);
	free_stack(&stack);
	return (0);
}
