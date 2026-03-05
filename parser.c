/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqroca- <raqroca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:46:43 by acanadil          #+#    #+#             */
/*   Updated: 2026/03/05 16:15:20 by raqroca-         ###   ########.fr       */
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
	t_flags	*flag;
	int		count;
	int		countbench;

	countbench = 0;
	count = 0;
	flag = flags;
	while (flag)
	{
		if (flag -> num > 0)
			count++;
		if (flag -> num == 0)
			countbench++;
		flag = flag -> next;
	}
	if (count > 1 || countbench > 1)
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

static int	found_flags(char **args, t_flags **flags)
{
	char	*d[6];
	int		p[2];
	char	*aux;

	p[0] = 0;
	p[1] = 0;
	d[0] = "--bench";
	d[1] = "--simple";
	d[2] = "--medium";
	d[3] = "--complex";
	d[4] = "--adaptive";
	while (*args)
	{
		p[1] = 0;
		while (p[1] < 5)
		{
			aux = *args;
			if (*aux == '\0')
				return (1);
			foun_in_arg(aux, flags, d[p[1]], p);
			p[1]++;
		}
		p[0]++;
		args++;
	}
	return (0);
}

t_list	*parser(char **arg, t_flags **flags, int fla)
{
	if (found_flags(arg, flags))
	{
		ft_flaclear(flags);
		return (NULL);
	}
	if (ft_flasize(*flags) > fla)
	{
		ft_flaclear(flags);
		return (NULL);
	}
	if (!no_repit(*flags))
	{
		ft_flaclear(flags);
		return (NULL);
	}
	return (parser_int(arg, *flags));
}
