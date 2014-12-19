/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 15:29:51 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/19 15:30:47 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"

char	**ft_ls(char **argv)
{
	DIR				*dirp;
	struct dirent	*read;
	int				j;
	char			**tab;

	j = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * ft_ls_count_files(argv) + 1)))
		return (NULL);
	if ((dirp = opendir(".")) != NULL)
	{
		while ((read = readdir(dirp)) != NULL)
		{
			if (!(tab[j] = ft_strdup(read->d_name)))
				return (NULL);
			if (tab[j][0] != '.')
				j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
