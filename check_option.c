/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 10:39:21 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/09 16:17:09 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include "libft.h"

char		**check_option(char **argv, int argc)
{
	char **tab;
	int i;
	int j;
	char tmp[2];

	i = 1;
	j = 1;
	if (argv[i][j] == 'a' && argv[i][j + 1] == '\0')
		tab = ft_ls_option_a(argv, argc);
	else if (argv[i][j] == 'l' && argv[i][j + 1] == '\0')
		ft_putstr("faire l'option -l");
	else if (argv[i][j] == 'R' && argv[i][j + 1] == '\0')
		tab = ft_ls_option_R(argv, argc);
	else if ((argv[i][j] == 'a' && argv[i][j + 1] != 'l')
			 || (argv[i][j] == 'a' && argv[i][j + 1] != 'R')
			 ||(argv[i][j] == 'r' && argv[i][j + 1] != 't'))
	{
		tmp[0] = argv[i][j + 1];
		tmp[1] = '\0';
		if (!(tab = (char **)malloc(sizeof(char *) * 2)))
			return (NULL);
		tab[0] = ft_strdup("ls: illegal option --");
		tab[0] = ft_strjoin(tab[0], tmp);
		tab[0] = ft_strjoin(tab[0], "\nusage: ls [-ABCFGHLOPRSTUWabcdefghijklmnopqrstuwx1] [file ...]");
	}
	else
	{
		if (!(tab = (char **)malloc(sizeof(char *) * 2)))
			return (0);
			tab[0] = ft_strdup("ls: illegal option --");
			tab[1] = NULL;
	}
	return (tab);
}
