/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqroca- <raqroca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:32:37 by raqroca-          #+#    #+#             */
/*   Updated: 2026/03/06 13:23:05 by raqroca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
** BASIC CHUNK SORT ALGORITHM (O(n * sqrt(n))):
** Baseline chunk sort without rb optimization.
** 1. assign_pos() normalizes all values to positions 0..n-1.
** 2. The stack is divided into chunks of size sqrt(n).
**    Elements whose position falls within the current chunk
**    range are pushed to B (pb); all others rotate forward (ra).
**    Once 'chunk' elements have been pushed, the limit advances
**    to the next chunk boundary.
** 3. Once A is empty, return_max_to_a() is called repeatedly:
**    it finds the maximum position in B, rotates B by the
**    shortest path (rb or rrb) to bring it to the top, then
**    pushes it back to A (pa). This rebuilds A in sorted order.
** No rb trick is applied during the push phase, so B is
** unsorted within each chunk — this is the key difference
** from the optimized complex version.
*/

static void	moveall_a(t_stack **stack, int print)
{
	while ((*stack)-> stackb)
		return_max_to_a(stack, print);
}

void	medium(t_stack **stack, int print)
{
	int	chunk;
	int	limit;
	int	move;

	chunk = ft_sqrt(ft_lstsize((*stack)-> stacka));
	move = 0;
	limit = chunk;
	assign_pos((*stack)-> stacka);
	while ((*stack)-> stacka)
	{
		if ((*stack)-> stacka -> pos < limit)
		{
			pb(stack, print);
			move++;
		}
		else
			ra(stack, print);
		if (move == chunk)
		{
			limit += chunk;
			move = 0;
		}
	}
	moveall_a(stack, print);
}
