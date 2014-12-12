/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:35:51 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/12 16:09:58 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>
#include <sys/stat.h>

char 		**ft_ls_option_l(char **tab)
{
	char *tmp;
	struct stat sb;
	int i;
	int count;
	char **ret_tab;

	tmp = ft_strnew(10);
	i = 0;
	count = 0;
	while (tab[count])
		count ++;
	printf("testoptiobkjgsdzjhweskdjzxhcjsdmnzxbjmdfsbxzcjmeshdzxnc jsdhzxbcjesdhzxbc jdabszxjmbdqwa sxzjb wahsz");
	ret_tab = (char **)malloc(sizeof(char *) * count + 1);
	count = 0;
	while (tab[count])
	{
		stat(tab[count], &sb);
		if (S_ISREG(sb.st_mode))
			tmp[i] =  '-';
		if (S_ISLNK(sb.st_mode))
			tmp[i] = 'l';
		if (S_ISDIR(sb.st_mode))
			tmp[i] = 'd';
		if (S_ISBLK(sb.st_mode))
			tmp[i] = 'b';
		if (S_ISCHR(sb.st_mode))
			tmp[i] = 'c';
		if (S_ISFIFO(sb.st_mode))
			tmp[i] = '|';
		i++;
		if (sb.st_mode & S_IRUSR)
			tmp[i++] = 'r';
		else
			tmp[i++] = '-';
		if (sb.st_mode & S_IWUSR)
			tmp[i++] = 'w';
		else
			tmp[i++] = '-';
		if (sb.st_mode & S_IXUSR)
			tmp[i++] = 'x';
		else
			tmp[i++] = '-';
		if (sb.st_mode & S_IRGRP)
			tmp[i++] = 'r';
		else
			tmp[i++] = '-';
		if (sb.st_mode & S_IWGRP)
			tmp[i++] = 'w';
		else
			tmp[i++] = '-';
		if (sb.st_mode & S_IXGRP)
			tmp[i++] = 'x';
		else
			tmp[i++] = '-';
		if (sb.st_mode & S_IROTH)
			tmp[i++] = 'r';
		else
			tmp[i++] = '-';
		if (sb.st_mode & S_IWOTH)
			tmp[i++] = 'w';
		else
			tmp[i++] ='-';
		if (sb.st_mode & S_IXOTH)
			tmp[i++] = 'x';
		else
			tmp[i++] = '-';
		tmp[i] = '\0';
		tmp = ft_strjoin((char *)tmp,(char *) (ft_count_sous_dossiers(tab[count])));
		i = ft_strlen(tmp);
		/*	ret = ft_strdup(sb.st_uid);
		tmp = ft_strjoin(tmp, ret);
		ret = ft_strdup(sb.st_size);
		tmp = ft_strjoin(tmp, ret);
		ret = ft_strdup(sb.st_mtime);
		tmp = ft_strjoin(tmp, ret);*/
		tmp = ft_strjoin(tmp, tab[count]);
		printf(tmp);
		ret_tab[count] = ft_strdup(tmp);
		count++;
	}
	return (ret_tab);
}
