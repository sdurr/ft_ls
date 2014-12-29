/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_option_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 08:43:54 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/29 12:22:23 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static char **ft_transfer(char **tab, int i, int j)
{
	char		*tmp;

	tmp = ft_strdup(tab[i]);
	tab[i] = ft_strdup(tab[j]);
	tab[j] = ft_strdup(tmp);
	return (tab);
}

char		**ft_ls_option_t(char **tab, int i, int j, char **tab_old)
{
	struct stat first;
	struct stat second;

	if ((ft_strchr(tab[i], ':')) != NULL)
		return (ft_ls_t_argv(tab_old));
	while (tab[i])
	{
		j = i;
		while (tab[j])
		{
			stat(tab[i], &first);
			stat(tab[j], &second);
			if (first.st_mtime < second.st_mtime)
				tab = ft_transfer(tab, i, j);
			if (first.st_mtime == second.st_mtime)
				if ((ft_strcmp(tab[i], tab[j])) > 0)
					tab = ft_transfer(tab, i, j);
			j++;
		}
		i++;
	}
	return (tab);
}
