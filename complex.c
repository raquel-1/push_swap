/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqroca- <raqroca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:26:07 by raqroca-          #+#    #+#             */
/*   Updated: 2026/03/02 15:58:56 by raqroca-         ###   ########.fr       */
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

** assign_pos
** Calculates and assigns a relative rank (0 to N-1) to each node.
** It stores this rank in the 'pos' field of the structure, allowing 
** the Radix algorithm to sort based on relative order rather than 
** the raw 'num' values, which could be negative or very large.

** complex
** This function sorts large lists (such as 100 or 500 numbers):
** 1. First, it assigns each number a position (0, 1, 2...).
** 2. Then, it checks those numbers ‘bit by bit’.
** 3. If a number has a “0” in that bit, it moves it to Stack B.
** 4. If it has a “1”, it leaves it in Stack A, sending it to the end.
** 5. At the end of each round, it returns everything from B to Stack A.
** 6. It repeats this until all the numbers are in order.
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

static void	radix_process(t_stack **stack, int i, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if ((((*stack)->stacka->pos >> i) & 1) == 0)
			pb(stack);
		else
			ra(stack);
		j++;
	}
	while ((*stack)->stackb != NULL)
		pa(stack);
}

void	complex(t_stack **stack)
{
	int	i;
	int	size;
	int	max_bits;

	if (!stack || !(*stack) || !(*stack)->stacka)
		return ;
	if (is_sorted((*stack)->stacka))
		return ;
	assign_pos((*stack)->stacka);
	size = ft_lstsize((*stack)->stacka);
	max_bits = count_bits(size - 1);
	i = 0;
	while (i < max_bits)
	{
		radix_process(stack, i, size);
		i++;
	}
}
