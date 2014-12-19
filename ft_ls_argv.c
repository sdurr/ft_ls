/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:35:51 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/19 16:03:03 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"

char	**ft_ls_argv(char **argv, int argc, int nb_argv, char ***tab_argv)
{
	DIR				*dirp;
	struct dirent	*read;
	char			**tab;
	int				j;

	j = 0;
	tab = (char **)malloc(sizeof(char *) * ft_ls_count_files(argv) + 1);
	while (argv[j])
	{
		if ((dirp = opendir(argv[j])) == NULL && (test_files(argv[j])) == NULL)
			argv = ft_no_files_or_directory(argv, j--, tab_argv);
		j++;
	}
	j = 0;
	while (*argv)
	{
		if ((dirp = opendir(*argv)) != NULL)
		{
			if (argc - nb_argv > 2)
				tab[j++] = ft_strjoin(*argv, ":");
			while ((read = readdir(dirp)) != NULL)
				if ((tab[j] = ft_strdup(read->d_name)) && tab[j][0] != '.')
					j++;
		}
		else if (test_files(*argv) != NULL)
			tab[j++] = ft_strdup(*argv);
		argv++;
	}
	tab[j] = NULL;
	return (tab);
}
