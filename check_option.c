/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 10:39:21 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/08 14:21:23 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_option(char **argv)
{
	int i;
	int j;

	j = 1
	i = 1;
	if (argv[j][0] != '-')
		ft_ls(argv[j]);
		while (argv[j][i])
		{
			if (argv[j][i] == 'a')
			{
				while (argv[j])
				{
					ft_ls_argv(argv[j++]);
					ft_putchar('\n');
				}
			if (argv[j][i] == 'r')
			{
				while (argv[j])
					ft_ls_revers_order(argv[j]);
			}
			if (argv[j][i] == 't')
			{
				while (argv[j])
					ft_ls_trie_date(argv[j]);

			}
			if (argv[j][i] == 'R')
			{
				while (argv[j++])
					ft_ls_recursive(argv[j]);
			}
			if (argv[j][i] != 'a' && argv[i] != 'r' && argv[i] != 't' && argv[i] != 'R')
			{
				ft_putstr("ls : illegal option --");
				ft_putchar(argv[j][i]);
				return (-1);
			}
			i++;
		}
		return (0);
}
