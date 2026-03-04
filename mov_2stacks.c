/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_2stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:46:52 by acanadil          #+#    #+#             */
/*   Updated: 2026/03/04 12:11:24 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

void	rr(t_stack **stack, int print)
{
	t_bench	*bench;

	bench = (*stack)->calc;
	if (rotateall(stack))
	{
		if (print)
			write(1, "rr\n", 3);
		bench->rr++;
		bench->total++;
	}
}

void	ss(t_stack **stack, int print)
{
	t_bench	*bench;

	bench = (*stack)->calc;
	if (swapall(stack))
	{
		if (print)
			write(1, "ss\n", 3);
		bench->ss++;
		bench->total++;
	}
}

void	rrr(t_stack **stack, int print)
{
	t_bench	*bench;

	bench = (*stack)->calc;
	if (revrotateall(stack))
	{
		if (print)
			write(1, "rrr\n", 4);
		bench->rrr++;
		bench->total++;
	}
}
