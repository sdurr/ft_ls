/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_option_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 08:43:54 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/16 10:11:50 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	**ft_ls_option_t(char **tab)
{
	int i;
	struct stat first;
	struct stat second;
	char *tmp;
	int j;

	i = 0;
	while (tab[i])
	{
		j = i;
		while (tab[j])
		{
			stat(tab[i], &first);
			stat(tab[j], &second);
			if (first.st_mtime < second.st_mtime && (ft_strchr(tab[i], ':')) == NULL)
			{
				tmp = ft_strdup(tab[i]);
				tab[i] = ft_strdup(tab[j]);
				tab[j] = ft_strdup(tmp);
			}
			if (first.st_mtime == second.st_mtime && (ft_strchr(tab[i], ':')) == NULL)
			{
				if ((ft_strcmp(tab[i], tab[j])) > 0)
				{
					tmp = ft_strdup(tab[i]);
					tab[i] = ft_strdup(tab[j]);
					tab[j] = ft_strdup(tmp);
				}
			}
			j++;
		}
		i++;
	}
	return(tab);
}
