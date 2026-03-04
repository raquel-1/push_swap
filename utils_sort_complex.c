/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_complex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:35:12 by raqroca-          #+#    #+#             */
/*   Updated: 2026/03/04 12:23:49 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_by_pos(t_stack **stack, int print)
{
	if ((*stack)->stacka->pos > (*stack)->stacka->next->pos)
		sa(stack, print);
}

void	sort_three_by_pos(t_stack **stack, int print)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->stacka->pos;
	second = (*stack)->stacka->next->pos;
	third = (*stack)->stacka->next->next->pos;
	if (first < second && second < third)
		return ;
	if (first > second && first > third)
	{
		ra(stack, print);
		if ((*stack)->stacka->pos > (*stack)->stacka->next->pos)
			sa(stack, print);
	}
	else if (second > first && second > third)
	{
		rra(stack, print);
		if ((*stack)->stacka->pos > (*stack)->stacka->next->pos)
			sa(stack, print);
	}
	else
	{
		sa(stack, print);
	}
}

void	sort_four_by_pos(t_stack **stack, int print)
{
	while ((*stack)->stacka->pos != 0)
		ra(stack, print);
	pb(stack, print);
	sort_three_by_pos(stack, print);
	pa(stack, print);
}

void	sort_five_by_pos(t_stack **stack, int print)
{
	while ((*stack)->stacka->pos != 0)
		ra(stack, print);
	pb(stack, print);
	while ((*stack)->stacka->pos != 1)
		ra(stack, print);
	pb(stack, print);
	sort_three_by_pos(stack, print);
	pa(stack, print);
	pa(stack, print);
}

void	tiny_sort_by_pos(t_stack **stack, int size, int print)
{
	if (size == 2)
		sort_two_by_pos(stack, print);
	else if (size == 3)
		sort_three_by_pos(stack, print);
	else if (size == 4)
		sort_four_by_pos(stack, print);
	else if (size == 5)
		sort_five_by_pos(stack, print);
}
