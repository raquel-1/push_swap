/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqroca- <raqroca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:32:37 by raqroca-          #+#    #+#             */
/*   Updated: 2026/03/06 13:22:44 by raqroca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
** This algorithm divides the stack into multiple "chunks" based on the
** relative positions (indices) of the numbers.
** 1. Pre-sorting phase (A to B): Elements are pushed to Stack B if they fall
** within the current chunk range. If an element is in the lower half of 
** the current chunk, it's rotated to the bottom of B (rb) to keep 
** Stack B semi-sorted, reducing future moves.
** 2. Final sorting phase (B to A): Once A is empty, the algorithm repeatedly
** finds the maximum value in B and pushes it back to A using the 
** shortest rotation path (rb or rrb).
*/
int	ft_sqrt(int n)
{
	int	i;

	if (n <= 0)
		return (0);
	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

void	return_max_to_a(t_stack **stack, int print)
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

static void	chunk_algorit(t_stack **stack, int chunk, int print)
{
	int	limit;

	limit = 0;
	while ((*stack)->stacka)
	{
		if ((*stack)->stacka->pos <= limit)
		{
			pb(stack, print);
			limit++;
		}
		else if ((*stack)->stacka->pos <= (limit + chunk))
		{
			pb(stack, print);
			rb(stack, print);
			limit++;
		}
		else
			ra(stack, print);
	}
}

void	complex(t_stack **stack, int print)
{
	int	chunk;
	int	size;

	if (!stack || !(*stack) || !(*stack)->stacka)
		return ;
	if (is_sorted((*stack)->stacka))
		return ;
	assign_pos((*stack)->stacka);
	size = ft_lstsize((*stack)->stacka);
	if (size <= 5)
	{
		tiny_sort_by_pos(stack, size, print);
		return ;
	}
	chunk = ft_sqrt(size);
	if (size >= 50)
		chunk = chunk * 2;
	chunk_algorit(stack, chunk, print);
	while ((*stack)->stackb)
		return_max_to_a(stack, print);
}
