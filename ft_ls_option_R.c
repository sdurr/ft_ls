/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_option_R.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 14:25:46 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/11 13:18:00 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	**ft_ls_option_r(char **tab)
{

	char **new_tab;
	char *tmp;
	int i;
	int j;

	j = 0;
	i = 0;
	while (tab[i])
		i++;
	if (!(new_tab = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	new_tab[i] = NULL;
	i--;
	while (i >= j)
	{
		tmp = ft_strdup(tab[i]);
			new_tab[j] = tmp;
		new_tab[i] = tab[j];
		i--;
		j++;
	}
	return (new_tab);
}

