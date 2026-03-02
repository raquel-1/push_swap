/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqroca- <raqroca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:26:07 by raqroca-          #+#    #+#             */
/*   Updated: 2026/03/02 12:26:03 by raqroca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
** This function calculates the number of bits needed to represent 
** the largest integer in the stack (max_n). 
**
** The right shift operator (>>) is used to analyze 
** the binary structure of the number:
** 1. In each iteration, we evaluate the value resulting from shifting 'n_bits' 
** positions to the right.
** 2. The shift removes the least significant bit (the one on the right).
** 3. The loop ends when the resulting value is equal to 0, indicating 
** that all significant bits have been processed.
**
** Technical analysis (Example with max_n = 5):
** - [1] [0] [1] (Value: 5) -> Shift  0: 5 != 0 (True) -> n_bits = 1
** -  0  [1] [0] (Value: 2) -> Shift  1: 2 != 0 (True) -> n_bits = 2
** -  0   0  [1] (Value: 1) -> Shift  2: 1 != 0 (True) -> n_bits = 3
** -  0   0   0  (Value: 0) -> Offset 3: 0 != 0 (False) -> Returns 3


*/

static int	count_bits(int max_n)
{
	int	n_bits;

	n_bits = 0;
	while ((max_n >> n_bits) != 0)
	{
		n_bits++;
	}
	return (n_bits);
}

static void	assign_pos(t_list *stacka)
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

void	complex(t_stack **stack)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	if (!stack || !(*stack) || !(*stack)->stacka)
		return ;
	assign_pos((*stack)->stacka);
	max_bits = count_bits(get_max((*stack)->stacka));
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = ft_lstsize((*stack)->stacka);
		while (j++ < size)
		{
			if ((((*stack)->stacka->pos >> i) & 1) == 1)
				ra(stack);
			else
				pb(stack);
		}
		i++;
	}
	while ((*stack)->stackb != NULL)
		pa(stack);
}
