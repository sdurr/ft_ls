/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:35:51 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/19 14:54:05 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>
#include <sys/stat.h>

void 		ft_ls_option_l(char **tab)
{
	struct stat sb;
	int count;
	int c;

	count = 0;
	c = 0;
	if ((ft_strchr(tab[count], ':')) == NULL && tab[count] && (test_files(tab[count])) == NULL)
		ft_total_blocks(tab);
	while (tab[count])
	{
		if ((ft_strchr(tab[count], ':')) != NULL)
		{
				ft_total_blocks(tab);
				ft_putstr(tab[count]);
				count++;
		}
		if ((stat(tab[count], &sb)) == -1)
		{
			count++;
		}
		ft_permission(tab[count]);
		c = ft_count_sous_dossiers(tab[count]);
		if (c < 10)
			ft_putstr("   ");
		else if (c < 99 && c > 9)
			ft_putstr("  ");
		else if (c < 999 && c > 99)
			ft_putstr(" ");
		else
			ft_putstr("");
		ft_putnbr(c);
		ft_putstr(" ");
		ft_noms_proprietaire(tab[count]);
		ft_putstr(" ");
		ft_time(tab[count]);
		if ((ft_strrchr(tab[count], '/')) != NULL)
		{
			tab[count] = ft_strrchr(tab[count], '/');
			tab[count]++;
		}
		ft_putstr(tab[count]);
		ft_putchar('\n');
		count++;
	}
}
