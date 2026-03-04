/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:20:40 by acanadil          #+#    #+#             */
/*   Updated: 2026/03/04 12:07:55 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENTS_H
# define MOVEMENTS_H

# include "push_swap.h"

void	rra(t_stack **stack, int print);
void	rrb(t_stack **stack, int print);
void	rrr(t_stack **stack, int print);
void	sa(t_stack **stack, int print);
void	sb(t_stack **stack, int print);
void	ss(t_stack **stack, int print);
void	pa(t_stack **stack, int print);
void	pb(t_stack **stack, int print);
void	ra(t_stack **stack, int print);
void	rb(t_stack **stack, int print);
void	rr(t_stack **stack, int print);

int		push(t_list **stack, t_list **dest);
int		revrotateall(t_stack **stack);
int		rotateall(t_stack **stack);
int		revrotate(t_list **stack);
int		swapall(t_stack **stack);
int		rotate(t_list **stack);
int		swap(t_list **stack);

#endif