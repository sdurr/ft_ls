/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:33:10 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/09 14:44:27 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_LS_H
# define	FT_LS_H

char	**ft_ls(char **argv); // s'il n'y a pas d'argv en parametre
char	**ft_ls_argv(char **argv, int argc); // s'il y a des argument en parametre
char	**check_option(char ** argv, int argc); // check quel option et renvoi vers la fonction
char	**ft_ls_option_a(char **argv, int argc); // option -a
//char	**ft_ls_option_l(char **argv, int argc); //option -l
char	**ft_ls_option_R(char **argv, int argc); // option -R
int		ft_ls_count_files(char **argv); // conte le nb de fichier dossiers
int		ft_ls_count_files_R(char **argv); //conte nb files dock and sous files
#endif
