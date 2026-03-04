/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:32:37 by raqroca-          #+#    #+#             */
/*   Updated: 2026/03/04 12:31:34 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	if (n <= 0)
		return (0);
	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static void	push_max_to_a(t_stack **stack, int print)
{
	int	size;
	int	max_pos;
	int	i;

	size = ft_lstsize((*stack)->stackb);
	max_pos = get_max_index((*stack)->stackb);
	i = get_pos_index((*stack)->stackb, max_pos);
	if (i <= size / 2)
	{
		while ((*stack)->stackb->pos != max_pos)
			rb(stack, print);
	}
	else
	{
		while ((*stack)->stackb->pos != max_pos)
			rrb(stack, print);
	}
	pa(stack, print);
}

void	medium(t_stack **stack, int print)
{
	int	i;
	int	chunk;
	int	size;

	i = 0;
	assign_pos((*stack)->stacka);
	size = ft_lstsize((*stack)->stacka);
	chunk = ft_sqrt(size);
	if (size > 100)
		chunk = chunk * 1.5;
	while ((*stack)->stacka)
	{
		/////from a to b
	}
	while ((*stack)->stackb)
		push_max_to_a(stack, print);
}
