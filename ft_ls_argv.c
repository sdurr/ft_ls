
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:35:51 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/19 14:08:34 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"

char 		**ft_ls_argv(char **argv, int argc, int nb_argv, char ***tab_argv)
{
	DIR *dirp;
	struct dirent *read;
	char **tab;
	int j;
	int i;
	int c;
	char *tab_eror;

	tab_eror = ft_strnew(1);
	c = argc - nb_argv;
	i = 0;
	j = 0;
	if (c > 0)
		if (!(tab = (char **)malloc(sizeof(char *) * ft_ls_count_files(argv) + 1)))
			return (NULL);
	while (argv[i])
		{
			if ((dirp = opendir(argv[i])) == NULL)
			{
				if ((test_files(argv[i])) == NULL)
				{
					tab_eror = ft_strjoin(tab_eror, "ft_ls: ");
					tab_eror = ft_strjoin(tab_eror, argv[i]);
					tab_eror = ft_strjoin(tab_eror, ":");
					tab_eror = ft_strjoin(tab_eror, " No such file or directory");
					tab_eror = ft_strjoin(tab_eror, "\n");
					argv = ft_rm_argv(argv, i, &c);
					rm_tab_argv(tab_argv, i);
						i--;
				}
			}
			i++;
		}
	ft_putstr(tab_eror);
	i = 0;
	c = argc - nb_argv;
	while (argv[i])
	{
		if ((dirp = opendir(argv[i])) != NULL) //
		{
			if (c > 2)
				if (!(tab[j++] = ft_strjoin(argv[i], ":")))
					return (NULL);
			while ((read = readdir(dirp)) != NULL) // lecture argv
			{
				tab[j] = ft_strdup(read -> d_name);
				if (tab[j][0] != '.') // pas de fichier cachees
					j++;
			}
		}
		i++;
	}
	tab[j] = NULL;
	if (c == 1)
		tab = ft_ls(argv);
	return (tab);
}
