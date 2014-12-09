/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:33:59 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/09 11:45:30 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdio.h>


int		main(int argc, char **argv)
{
	char **tab;
	int i;

	i = 0;
	tab = NULL;
	if (argc == 1)
		tab = ft_ls(argv);
	else
		tab = ft_ls_argv(argv, argc);
	while (tab[i])
	{
			ft_putstr(tab[i]);
			ft_putchar('\n');
		i++;
	}
	return (0);
}

