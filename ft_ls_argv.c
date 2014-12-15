/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:35:51 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/15 15:13:11 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"

char 		**ft_ls_argv(char **argv, int argc, int nb_argv)
{
	DIR *dirp;
	struct dirent *read;
	char **tab;
	int j;
	int i;
	int c;

	c = argc - nb_argv;
	i = 0;
	j = 0;
	if (c > 0)
		if (!(tab = (char **)malloc(sizeof(char *) * ft_ls_count_files(argv) +1)))
			return (NULL);
	while (argv[i])
		{
			if ((dirp = opendir(argv[i])) == NULL)
			{
			tab[j] = ft_strjoin("ft_ls: ", argv[i]);
			tab[j] = ft_strjoin(tab[j], " No such file or directory");
			j++;
			}
			i++;
		}
		i = 0;
		while (argv[i])
		{
			if ((dirp = opendir(argv[i])) != NULL) // ouverture argv[1] pointeur sur flux
			{
				if (argc > 2)
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
