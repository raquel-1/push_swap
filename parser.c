/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:46:43 by acanadil          #+#    #+#             */
/*   Updated: 2026/03/02 11:38:38 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_flags	*addflag(int fl, int p, char *fla)
{
	t_flags	*flag;

	flag = ft_flanew(fl, p, fla);
	return (flag);
}

static int	no_repit(t_flags *flags)
{
	t_flags	*bench;
	t_flags	*flag;
	int		count;

	count = 0;
	flag = flags;
	bench = flags;
	while (flag)
	{
		if (flag -> num < 4)
			count ++;
		flag = flag -> next;
	}
	if (count > 1)
		return (0);
	count = 0;
	while (bench)
	{
		if (bench -> num == 4)
			count ++;
		bench = bench -> next;
	}
	if (count > 1)
		return (0);
	return (1);
}

static void	foun_in_arg(char *args, t_flags **flags, char *d, int p[2])
{
	char	*str;

	while (*args)
	{
		if (strverif(args, d))
		{
			str = ft_strnstr(args, d, ft_strlen(args));
			ft_flaadd_back(flags, addflag(p[1], p[0], str));
			while (args != str)
				args++;
			args++;
		}
		else
			break ;
	}
}

static void	found_flags(char **args, t_flags **flags)
{
	char	*d[5];
	int		p[2];
	char	*aux;

	p[0] = 0;
	p[1] = 0;
	d[0] = "--simple";
	d[1] = "--medium";
	d[2] = "--complex";
	d[3] = "--adaptive";
	d[4] = "--bench";
	while (*args)
	{
		p[1] = 0;
		while (p[1] < 5)
		{
			aux = *args;
			foun_in_arg(aux, flags, d[p[1]], p);
			p[1]++;
		}
		p[0]++;
		args++;
	}
}

t_list	*parser(char **arg, t_flags **flags, int fla)
{
	found_flags(arg, flags);
	if (ft_flasize(*flags) > fla)
	{
		write(2, "Error\n", 6);
		ft_flaclear(flags);
		return (NULL);
	}
	if (!no_repit(*flags))
	{
		write(2, "Error\n", 6);
		ft_flaclear(flags);
		return (NULL);
	}
	return (parser_int(arg, *flags));
}
