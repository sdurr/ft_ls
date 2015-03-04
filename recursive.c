/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 09:03:39 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/04 10:28:30 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include "ft_ls.h"
#include "libft.h"

char **recursive(char *tab)
{
	DIR *dirp;
	int i;
	int j;
	char **tab_ret;
	struct dirent *read;
	char **test;
	char *path;

	i = 0;
	tab_ret = (char **)malloc(sizeof(char *) * ft_count_sous_dossiers(tab));
	test = (char **)malloc(sizeof(char *) * ft_count_sous_dossiers(tab));
	j = 0;
	i = 0;
	if ((dirp = opendir(tab)) != NULL)
	{
		while ((read = readdir(dirp)) != NULL)
		{
			if (ft_strncmp(read->d_name, ".", 1) != 0)
				tab_ret[j++] = ft_strdup(read->d_name);
			path = ft_strdup(tab);
			path = ft_strjoin(path, "/");
			path = ft_strjoin(path, tab_ret[j - 1]);
			if (open_file(path) == 1)
				test[i++] = ft_strdup(read->d_name);
		}
	}
	test[j] = NULL;
	tab_ret[j] = NULL;
	j = 0;
	return (tab_ret);
}
