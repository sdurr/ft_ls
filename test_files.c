/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 09:29:47 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/17 10:17:07 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>

char		*test_files(char *argv)
{
	DIR *dirp;
	struct dirent *read;
	char *tmp;
	int i;
	char *tmp2;

	if ((tmp2 = ft_strrchr(argv, '/')) != NULL)
		tmp2++;
	if ((dirp = opendir(argv)) == NULL)
	{
		if ((ft_strchr(argv, '/')) != NULL)
		{
			tmp = ft_strdup(argv);
			i = ft_strlen(tmp) - 1;
			while (tmp[i] != '/' && i >= 0)
			{
				tmp[i] = '\0';
				i--;
			}
			if ((dirp = opendir(tmp)) != NULL)
				while ((read = readdir(dirp)) != NULL)
				{
					if ((ft_strcmp(tmp2, read -> d_name)) == 0)
						return (argv);
				}
			return (NULL);
		}
		else
			if ((dirp = opendir(".")) != NULL)
				while ((read = readdir(dirp)) != NULL)
				{
					if ((ft_strcmp(argv, read -> d_name)) == 0)
						return (argv);
				}
		return (NULL);
	}
	return (NULL);
}
