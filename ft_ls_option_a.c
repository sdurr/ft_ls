/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:35:51 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/09 11:46:27 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char 		**ft_ls_option_a(char **argv, int argc)
{
	DIR *dirp;
	struct dirent *read;
	char **tab;
	int j;
	int i;

	i = 2;
	j = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * ft_ls_count_files(argv) +1)))
		return (NULL);
	while (argv[i])
	{
		if ((dirp = opendir(argv[i])) != NULL) // ouverture argv[1] pointeur sur flux
		{
			if (argc > 2)
			{
				if (!(tab[j] = ft_strjoin(argv[i], ":")))
					return (NULL);
				j++;
			}
			while ((read = readdir(dirp)) != NULL) // lecture argv
			{
				if (!(tab[j] = ft_strdup(read -> d_name)))
					return (NULL);
					j++;
			}
		}
		else
		{
			tab[j] = ft_strjoin("ft_ls: ", argv[i]);
			tab[j] = ft_strjoin(tab[j], " No such file or directory");
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
