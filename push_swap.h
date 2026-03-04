/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:24:08 by acanadil          #+#    #+#             */
/*   Updated: 2026/03/04 12:34:55 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include "libft/libft.h"
# include "ft_flags.h"
# include "movements.h"

int		strverif(char *str1, char *str2);
t_list	*parser(char **arg, t_flags **flags, int fla, int w);
t_list	*parser_int(char **arg, t_flags *flags, int w);
t_flags	*asignflag(const t_flags *flags, int j);
int		verifflag(const t_flags *flag, char **leter);
long	ft_atoi_long(const char *nptr);
int		strverifall(char *str1, char *str2);
void	save_numbers(char **arg, t_flags *flags, t_list **stacka);
void	makemove(t_stack **order, char *move);
char	*sel_strat(float sta);
void	print_bench(t_bench *bench);

int		get_min(t_list *stack);
int		get_max(t_list *stack);
int		is_sorted(t_list *stack);
int		get_position(t_list *stack, int value);
void	free_stack(t_stack **stack);
float	disorder(t_list *stack_a);
void	print_disorder(float d);
void	tiny_sort(t_stack **stack, int print);
void	assign_pos(t_list *stacka);
int		get_pos_index(t_list *stack, int pos_look);
int		get_max_index(t_list *stack);
/* complex sort */
void	tiny_sort_by_pos(t_stack **stack, int size, int print);
void	complex(t_stack **stack, int print);
void	medium(t_stack **stack, int print);
void	simple(t_stack **stack, int print);
void	adaptiv(t_stack **order, int print);

#endif