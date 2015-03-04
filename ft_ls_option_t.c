/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_option_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 08:43:54 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/04 11:03:09 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static char		**trim(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		tab[i] = ft_strchr(tab[i], '/');
			tab[i]+=1;
		i++;
	}
	return (tab);
}


static char		**ft_transfer(char **tab, int i, int j)
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

	if (tab_old[0])
		j = 0;
	while (tab[i])
	{
		j = i;
		while (tab[j])
		{
		if ((ft_strchr(tab[j], ':')) != NULL)
		{
			j++;
			i++;
		}
		lstat(tab[i], &first);
		lstat(tab[j], &second);
		if (first.st_mtime < second.st_mtime)
			tab = ft_transfer(tab, i, j);
		if (first.st_mtime == second.st_mtime)
			if ((ft_strcmp(tab[i], tab[j])) > 0)
				tab = ft_transfer(tab, i, j);
			j++;
		}
		i++;
	}
	tab = trim(tab);
	return (tab);
}
