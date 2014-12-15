/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_argv_open.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:17:40 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/15 14:52:41 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_ls.h"

char	**ft_tab_argv_open(char **tab)
{
	char **new_tab;
	int i;
	int k;
	int j;
	char *tmp;
	int s;

	s = 0;
	k = 0;
	i = 1;
	while (tab[i])
		i++;
	if (!(new_tab = (char **)malloc(sizeof(char *) * i)))
		return (NULL);
	i = 0;
	j = 0;
	while (tab[i])
	{
		if ((ft_strchr(tab[i], ':')) != NULL)
		{
			tmp = ft_strnew(ft_strlen(tab[i] +1));
			while (tab[i][s] != ':')
			{
				tmp[s] = tab[i][s];
				s++;
			}
		}
		new_tab[j] = ft_strjoin (tmp, "/");
		new_tab[j] = ft_strjoin (new_tab[j], tab[i]);
		j++;
		k++;
		i++;
	}
	ft_print_tab(new_tab);
	return (new_tab);
}
