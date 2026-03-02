/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 09:59:52 by acanadil          #+#    #+#             */
/*   Updated: 2026/03/02 11:39:21 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structur.h"
#include "ft_flags.h"
#include "push_swap.h"

t_flags	*asignflag(const t_flags *flags, int j)
{
	t_flags	*flag;
	t_flags	*aux;

	flag = NULL;
	while (flags)
	{
		if (flags -> pos == j)
		{
			aux = ft_flanew(flags->num, flags->pos, flags->flag);
			ft_flaadd_back(&flag, aux);
		}
		flags = flags -> next;
	}
	return (flag);
}

int	verifflag(const t_flags *flag, char **leter)
{
	char	*d;

	d = *leter;
	while (flag)
	{
		if (flag->flag == d)
		{
			while (*d && *d != ' ')
				d++;
			*leter = d;
			return (1);
		}
		flag = flag -> next;
	}
	return (0);
}

static int	letercorrect(char **arg)
{
	char	*aux;

	aux = *arg;
	if (!aux)
		return (0);
	if (*aux == '-')
		aux++;
	while (aux && ft_isdigit(*aux))
		aux++;
	*arg = aux;
	if (*aux != ' ' && *aux != '\0' && !ft_isdigit(*aux))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

static size_t	num_number(char **arg, t_flags *flags)
{
	size_t	i;
	int		j;
	char	*ptr;
	t_flags	*flag;

	j = 0;
	i = 0;
	while (arg[j])
	{
		ptr = arg[j];
		flag = asignflag(flags, j);
		while (*ptr)
		{
			while (*ptr && *ptr == ' ')
				ptr++;
			if (verifflag(flag, &ptr))
				continue ;
			if (!letercorrect(&ptr))
				return (0);
			i++;
		}
		ft_flaclear(&flag);
		j++;
	}
	return (i);
}

t_list	*parser_int(char **arg, t_flags *flags)
{
	size_t	size;
	t_list	*numbers;

	size = num_number(arg, flags);
	if (size == 0)
		return (NULL);
	numbers = NULL;
	save_numbers(arg, flags, &numbers);
	return (numbers);
}
