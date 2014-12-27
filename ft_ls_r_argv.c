/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_r_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 17:05:42 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/27 18:44:25 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "ft_ls.h"

char		**ft_ls_r_argv(char **tab)
{
	char	**new_tab;
	int		i;
	int		j;
	int		c;

	j = 0;
	i = 0;
	while (tab[i])
		i++;
	c = i;
	new_tab = (char **)malloc(sizeof(char *) * i + 1);
	while (i-- >= 0 && j < c)
	{
		while ((ft_strchr(tab[i], ':')) == NULL)
			i--;
		new_tab[j++] = ft_strdup(tab[i++]);
		while (tab[i] != NULL && (ft_strchr(tab[i], ':')) == NULL)
			i++;
		i--;
		while ((ft_strchr(tab[i], ':')) == NULL)
			new_tab[j++] = ft_strdup(tab[i--]);
	}
	new_tab[j] = NULL;
	return (new_tab);
}
