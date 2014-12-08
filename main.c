/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:33:59 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/08 18:03:11 by sdurr            ###   ########.fr       */
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
	{
		tab = ft_ls(argv);
		while (tab[i])
		{
			if (tab[i][0] != '.')
				printf("%s\n", tab[i]);
			i++;
		}
	}
	return (0);
}

