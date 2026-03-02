/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:25:33 by acanadil          #+#    #+#             */
/*   Updated: 2026/03/02 12:57:03 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sel_strat(float dis)
{
	if (dis < 0.2)
		return ("O(n^2)");
	else if (dis < 0.5)
		return ("O(n^2)");
	else
		return ("O(n log n)");
}

static void	print_syp(t_bench *bench)
{
	write(2, "sa: ", 4);
	print_num(bench -> sa);
	write(2, "sb: ", 4);
	print_num(bench -> sb);
	write(2, "ss: ", 4);
	print_num(bench -> ss);
	write(2, "pa: ", 4);
	print_num(bench -> pa);
	write(2, "pb: ", 4);
	print_num(bench -> pb);
}

static void	print_ryrr(t_bench *bench)
{
	write(2, "ra: ", 4);
	print_num(bench -> ra);
	write(2, "rb: ", 4);
	print_num(bench -> rb);
	write(2, "rr: ", 4);
	print_num(bench -> rr);
	write(2, "rra: ", 5);
	print_num(bench -> rra);
	write(2, "rrb: ", 5);
	print_num(bench -> rrb);
	write(2, "rrr: ", 5);
	print_num(bench -> rrr);
}

void	print_bench(t_bench *bench)
{
	write(2, "[bench] disorder:\t", 18);
	print_disorder(bench -> disorder);
	write(2, "\n", 1);
	write(2, "[bench] strategy:\t", 18);
	write(2, bench -> flag, ft_strlen(bench -> flag));
	write(2, " / ", 1);
	write(2, bench -> strategy, ft_strlen(bench -> strategy));
	write(2, "\n", 1);
	write(2, "[bench] total_ops:\t", 19);
	print_num(bench -> total);
	write(2, "\n", 1);
	write(2, "[bench] ", 8);
	print_syp(bench);
	write(2, "\n", 1);
	write(2, "[bench] ", 8);
	print_ryrr(bench);
	write(2, "\n", 1);
}

static void	print_num(long n)
{
	char	num;

	if (n == -2147483648)
		write(2, "-2147483648", 11);
	if (n < 0)
	{
		n = -n;
		write(2, "-", 1);
	}
	if (n >= 10)
		print_num(n / 10);
	num = 48 + (n % 10);
	write(2, &num, 1);
}
