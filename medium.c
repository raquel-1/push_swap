/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:32:37 by raqroca-          #+#    #+#             */
/*   Updated: 2026/03/06 13:02:02 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
