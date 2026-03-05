/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqroca- <raqroca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:57:52 by acanadil          #+#    #+#             */
/*   Updated: 2026/03/05 12:37:19 by raqroca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

int	push(t_list **stack, t_list **dest)
{
	t_list	*top;

	if (!stack || !(*stack))
		return (0);
	top = *stack;
	*stack = (*stack)->next;
	ft_lstadd_front(dest, top);
	return (1);
}

int	revrotate(t_list **stack)
{
	t_list	*last;
	t_list	*iter;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	iter = *stack;
	last = ft_lstlast(*stack);
	while (iter->next != last)
	{
		iter = iter->next;
	}
	iter->next = NULL;
	ft_lstadd_front(stack, last);
	return (1);
}

int	rotate(t_list **stack)
{
	t_list	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	first = *stack;
	(*stack) = first->next;
	first->next = NULL;
	ft_lstadd_back(stack, first);
	return (1);
}

int	swap(t_list **stack)
{
	t_list	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	second = (*stack)->next;
	(*stack)->next = second->next;
	ft_lstadd_front(stack, second);
	return (1);
}
