/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:02:07 by raqroca-          #+#    #+#             */
/*   Updated: 2026/03/04 12:34:44 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
sort_three: sorted - first bigger - second bigger - third bigger(else)

** assign_pos
** Calculates and assigns a relative rank (0 to N-1) to each node.
** It stores this rank in the 'pos' field of the structure, allowing 
** the Radix algorithm to sort based on relative order rather than 
** the raw 'num' values, which could be negative or very large.
*/

static void	sort_three(t_stack **stack, int print)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->stacka->num;
	second = (*stack)->stacka->next->num;
	third = (*stack)->stacka->next->next->num;
	if (first < second && second < third)
		return ;
	if (first > second && first > third)
	{
		ra(stack, print);
		if ((*stack)->stacka->num > (*stack)->stacka->next->num)
			sa(stack, print);
	}
	else if (second > first && second > third)
	{
		rra(stack, print);
		if ((*stack)->stacka->num > (*stack)->stacka->next->num)
			sa(stack, print);
	}
	else
	{
		sa(stack, print);
	}
}

void	tiny_sort(t_stack **stack, int print)
{
	int	size;

	if (!(*stack)->stacka || is_sorted((*stack)->stacka))
		return ;
	size = ft_lstsize((*stack)->stacka);
	if (size == 2)
	{
		if ((*stack)->stacka->num > (*stack)->stacka->next->num)
			sa(stack, print);
	}
	else if (size == 3)
	{
		sort_three(stack, print);
	}
}

void	assign_pos(t_list *stacka)
{
	t_list	*current;
	t_list	*compare;
	int		count;

	current = stacka;
	while (current != NULL)
	{
		count = 0;
		compare = stacka;
		while (compare != NULL)
		{
			if (compare->num < current->num)
				count++;
			compare = compare->next;
		}
		current->pos = count;
		current = current->next;
	}
}

int	get_pos_index(t_list *stack, int pos_look)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->pos == pos_look)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

int	get_max_index(t_list *stack)
{
	int	max_p;

	if (!stack)
		return (0);
	max_p = stack->pos;
	while (stack)
	{
		if (stack->pos > max_p)
			max_p = stack->pos;
		stack = stack->next;
	}
	return (max_p);
}
