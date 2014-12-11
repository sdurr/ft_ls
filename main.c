/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:33:59 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/11 13:19:24 by sdurr            ###   ########.fr       */
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
	flags = test_option(argv, &nb_argv);
	tab_argv = copy_argv(argv, nb_argv, argc);
	tab = ft_ls(argv);
	if (flags & OPT_A)
		tab = ft_ls_option_a(tab_argv, argc, nb_argv);
///	if (flags & OPT_R_R)
//		tab = ft_ls_option_r_r(tab_argv)
//	if (flags & OPT_L)
	//	tab = ft_ls_option_l(tab_argv, argc, nb_argv);
	//if (flags & OPT_T)
	///tab = ft_ls_option_t(argv, tab);
//	ft_print_tab(tab);
	if (flags & OPT_R)
		tab = ft_ls_option_r(tab);
	ft_print_tab(tab);
		return (0);
}

