/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_complex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqroca- <raqroca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:35:12 by raqroca-          #+#    #+#             */
/*   Updated: 2026/03/04 18:32:40 by raqroca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
** Sort 3 elements by comparing their positions.
** If they are already sorted (first < second < third), finish.
** If the 1º is the max, rotate it backwards and check if it needs to be swapped.
** If the 2º is the max, rotate it backwards and check if it needs to be swapped.
** In any other case, just swap the first two.

** Sort 4 elements (Minimum Extraction):
** 1. Identifies the position of the smallest element (pos=0).
** 2. Moves it to the top of Stack A using the shortest path (ra/rra).
** 3. Pushes it to Stack B, sorts the remaining 3 with sort_three_by_pos,
** and finally returns the 0 to the top of A.

** Sort 5 elements (Dual Minimum Extraction):
** 1. Finds the smallest element (pos=0) and moves it to the top (ra/rra) 
** before pushing it to Stack B.
** 2. Repeats the process for the next smallest element (pos=1) and
** pushes it to Stack B as well.
** 3. Sorts the 3 remaining elements in A with sort_three_by_pos.
** 4. Returns both elements from B to A (pos 1, then pos 0) to complete 
** the ascending order.
*/

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
	int	size;
	int	index;

	size = ft_lstsize((*stack)->stacka);
	index = get_pos_index((*stack)->stacka, 0);
	if (index <= size / 2)
	{
		while ((*stack)->stacka->pos != 0)
			ra(stack, print);
	}
	else
	{
		while ((*stack)->stacka->pos != 0)
			rra(stack, print);
	}
	pb(stack, print);
	sort_three_by_pos(stack, print);
	pa(stack, print);
}

void	sort_five_by_pos(t_stack **stack, int print)
{
	int	size;
	int	index;

	size = ft_lstsize((*stack)->stacka);
	index = get_pos_index((*stack)->stacka, 0);
	if (index <= size / 2)
		while ((*stack)->stacka->pos != 0)
			ra(stack, print);
	else
		while ((*stack)->stacka->pos != 0)
			rra(stack, print);
	pb(stack, print);
	size = ft_lstsize((*stack)->stacka);
	index = get_pos_index((*stack)->stacka, 1);
	if (index <= size / 2)
		while ((*stack)->stacka->pos != 1)
			ra(stack, print);
	else
		while ((*stack)->stacka->pos != 1)
			rra(stack, print);
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
