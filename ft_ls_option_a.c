/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:35:51 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/19 18:07:53 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	**ft_ls_option_a(char **argv, int argc, int nb)
{
	DIR				*dirp;
	struct dirent	*read;
	char			**tab;
	int				j;
	int				i;

	i = 0;
	j = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * ft_ls_count_files(argv) + 1)))
		return (NULL);
	i = -1;
	while (argv[++i])
		if ((dirp = opendir(argv[i])) != NULL)
		{
			if (argc - nb > 2)
				tab[j++] = ft_strjoin(argv[i], ":");
			while ((read = readdir(dirp)) != NULL)
				tab[j++] = ft_strdup(read->d_name);
		}
	if (!argv[0])
		if ((dirp = opendir(".")) != NULL)
			while ((read = readdir(dirp)) != NULL)
				tab[j++] = ft_strdup(read->d_name);
	tab[j] = NULL;
	return (tab);
}
