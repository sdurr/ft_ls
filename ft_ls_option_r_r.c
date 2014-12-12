/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_option_r_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 08:52:04 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/12 11:25:33 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

char **ft_ls_option_r_r(char **av, char **tab, int nb_argv, int argc)
{
	int i;
	char **new_tab;
	int j;
	int k;
	DIR *dirp;
	struct dirent *read;
	DIR *over;
	DIR *last;

	j = 1;
	i = 0;
	if (!(tab = (char **)ft_ls_count_files_R(av, tab, nb_argv, argc)))
		return (NULL);
	while (tab[i])
	{
		new_tab[i] = tab[i];
		i++;
	}
}
k = i;
i = 0
while (new_tab[i])
{
//	if (ft_strchr(new_tab[k], ':') != NULL && k == 0)
	//	k++;
//	if (ft_strchr(new_tab[k], ':') != NULL && k > 0)
	if ((dirp = opendir(new_tab[i])) != NULL )
	{
		new_tab[k] = ft_strdup(new_tab[i]);
		while ((read = readdir(dirp)) != NULL)
		{
			new_tab[k] = ft_strjoin(new_tab[k], "/");
			new_tab[k] = ft_strjoin(new_tab[k], read -> d_name);
			while ((over = opendir(read -> d_name)) != NULL)
			{
				while ((read = readdir(over)) != NULL)
				{
					if ((last = opendir(read -> d_name)) == NULL)
						new_tab[k] = ft_strjoin(new_tab[k], ":");
					new_tab[k] = ft_strjoin(new_tab[k], "/");
					new_tab[k] = ft_strjoin(new_tab[k], read -> d_name);
				}
			}
}
