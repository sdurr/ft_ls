/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:35:51 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/09 10:15:54 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	**ft_ls(char **argv)
{
	DIR *dirp;
	struct dirent *read;
	int j;
	char **tab;

	j = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * ft_ls_count_files(argv) + 1)))
		return (NULL);
	if ((dirp = opendir(".")) != NULL) // ouverture argv[1] pointeur sur flux
	{
		while ((read = readdir(dirp)) != NULL) // lecture argv
		{
			if (!(tab[j] = ft_strdup(read -> d_name))) //stock noms fichier ou dossiers dans tableau
				return (NULL);
			if (tab[j][0] != '.')
				j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
