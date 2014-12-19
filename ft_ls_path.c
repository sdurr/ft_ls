/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 10:46:55 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/19 14:22:21 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>

char	**ft_ls_path(char **tab_argv, char **tab)
{
	int i;
	char **new_tab;
	int j;
	int k;

	k = 0;
	j = 0;
	while (tab[i])
		i++;
	if (!(new_tab = (char **)malloc(sizeof(char *) * i + 1)))
		return(NULL);
	i = 0;
	if ((ft_strchr(tab[i], ':')) == NULL)
	{
		while (tab[i])
		{
			if ((test_files(tab[i])) == NULL)
            {
                new_tab[k] = ft_strdup(tab_argv[j]);
                new_tab[k] = ft_strjoin(new_tab[k], "/");
                new_tab[k] = ft_strjoin(new_tab[k], tab[i]);
                i++;
                k++;
            }
/*			else
			{
				new_tab[k] = ft_strdup("./");
				new_tab[k] = ft_strjoin(new_tab[k], tab[i]);
				i++;
				k++;
				}*/
		}
	}
	else
	{
		i = 0;
		while (tab_argv[j])
		{
			while (tab[i] && (ft_strchr(tab[i], ':')) != NULL)
			{
				new_tab[k] = ft_strdup(tab_argv[j]);
				new_tab[k] = ft_strjoin(new_tab[k], "/");
				new_tab[k] = ft_strjoin(new_tab[k], tab[i]);
				i++;
				k++;
			}
			j++;
		}
	}
	new_tab[k] = NULL;
	return (new_tab);
}
