/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_option_R.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 14:25:46 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/11 13:03:50 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"

char	**ft_ls_option_r(char **tab)
{

	char **new_tab;
	char *tmp;
	int i;

	i = 0;
	while (tab[i])
		i++;
	if (!(new_tab = (char **)malloc

}

