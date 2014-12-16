/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:33:59 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/16 11:10:12 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
#include "libft.h"

int		main(int argc, char **argv)
{
	int flags;
	char **tab;
	char **tab_argv;
	int nb_argv;

	nb_argv = 0;
	if (argc == 1)
	{
		tab = ft_ls(argv);
		ft_print_tab(tab);
		return (0);
	}
	if ((flags = test_option(argv, &nb_argv)) == -1)
		return (0);
	tab_argv = copy_argv(argv, nb_argv, argc);
	tab = ft_ls_argv(tab_argv, argc, nb_argv);
	if (flags & OPT_A)
		tab = ft_ls_option_a(tab_argv, argc, nb_argv);
	if (tab_argv[0])
	{
		if (flags & OPT_T)
			tab = ft_ls_option_t(tab);
		if (flags & OPT_R)
				tab = ft_ls_option_r(tab_argv);
			if (flags & OPT_L)
			{
				tab = ft_ls_path(tab_argv, tab);
				ft_ls_option_l_permissions(tab);
			}
			else
				ft_print_tab(tab);
	}
	else
	{
		if (flags & OPT_T)
			tab = ft_ls_option_t(tab);
		if (flags & OPT_R)
			tab = ft_ls_option_r(tab);
		if (flags & OPT_L)
		{
			ft_ls_option_l_permissions(tab);
		}
		else
			ft_print_tab(tab);
	}

//	ft_print_tab(tab);
		return (0);
}

