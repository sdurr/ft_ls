/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_option_R.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 14:25:46 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/09 15:05:27 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"

char	**ft_ls_option_R(char **argv, int argc)
{
//	DIR *dirp;
	//struct dirent *read;
	///int j;
	char **tab;
	int i;
	int j;

	i = 0;
//	j = 0;
	argc = argc - 1;
	if (argv[i])
		if (!(tab = (char **)malloc(sizeof(char *) * 2)))
			return (NULL);
	tab[0] = "blabla";
	j = ft_ls_count_files_R(argv);
	j = j - 1;
	tab[1] = NULL;
	return (tab);
}
