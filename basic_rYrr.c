/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_rYrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:39:50 by acanadil          #+#    #+#             */
/*   Updated: 2026/03/04 12:18:06 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

void	ra(t_stack **stack, int print)
{
	t_bench	*bench;

	bench = (*stack)->calc;
	if (rotate(&(*stack)->stacka))
	{
		if (print)
			write(1, "ra\n", 3);
		bench->ra++;
		bench->total++;
	}
}

void	rb(t_stack **stack, int print)
{
	t_bench	*bench;

	bench = (*stack)->calc;
	if (rotate(&(*stack)->stackb))
	{
		if (print)
			write(1, "rb\n", 3);
		bench->rb++;
		bench->total++;
	}
}

void	rra(t_stack **stack, int print)
{
	t_bench	*bench;

	bench = (*stack)->calc;
	if (revrotate(&(*stack)->stacka))
	{
		if (print)
			write(1, "rra\n", 4);
		bench->rra++;
		bench->total++;
	}
}

void	rrb(t_stack **stack, int print)
{
	t_bench	*bench;

	bench = (*stack)->calc;
	if (revrotate(&(*stack)->stackb))
	{
		if (print)
			write(1, "rrb\n", 4);
		bench->rrb++;
		bench->total++;
	}
}
