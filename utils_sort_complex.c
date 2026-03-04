/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_complex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:35:12 by raqroca-          #+#    #+#             */
/*   Updated: 2026/03/04 12:41:02 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
** Sort 3 elements by comparing their positions.
** If they are already sorted (first < second < third), finish.
** If the 1º is the max, rotate it backwards and check if it needs to be swapped.
** If the 2º is the max, rotate it backwards and check if it needs to be swapped.
** In any other case, just swap the first two.

** Sort 4 elements using the minimum extraction method.
** First, rotate stack A until the element with pos=0 is at the top,
** then push it to B. Next, sort the remaining 3 elements in A
** using sort_three_by_pos(), and finally return the 0 from B to A,
** leaving the stack completely sorted in ascending order.

** Sort 5 elements by extracting the two smallest ones to B.
** First, rotate A until you find pos=0, then push it to B.
** Then rotate A until you find pos=1, and push it to B as well.
** With the 3 remaining elements in A, sort them with sort_three_by_pos().
** Finally, return the two elements from B in the correct order (1 then 0),
** leaving stack A completely sorted in ascending order.
*/

void	sort_two_by_pos(t_stack **stack)
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
