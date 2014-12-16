    /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:33:10 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/16 11:07:43 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_LS_H
# define	FT_LS_H

# define OPT_L 4
# define OPT_A 8
# define OPT_T 16
# define OPT_R 32
# define OPT_R_R 64

char	**ft_ls(char **argv); // s'il n'y a pas d'argv en parametre
char	**ft_ls_argv(char **argv, int argc, int nb_argv); // s'il y a des argument en parametre
void	check_option_illegal(char *argv); // check quel option et renvoi vers la fonction
char	**ft_ls_option_a(char **argv, int argc, int nb); // option -a
void	ft_ls_option_l_permissions(char **tab); //option -l
char	**ft_ls_option_r(char **tab); // option -r
char	**ft_ls_option_t(char **tab); // option -t
int		ft_count_sous_dossiers(char *tab); // count le nom de dossier dans un dossier
int		ft_ls_count_files(char **argv); // conte le nb de fichier dossiers
int		ft_ls_count_files_R(char **argv, int nb_argv, int argc); //conte nb files dock and sous files
int		test_option(char **argv, int *nb); // test options with bitwise
char	**ft_tab_argv_open(char **tab);
char	**ft_ls_path(char **tab_argv, char **tab);
void	ft_print_tab(char **tab);
void	ft_noms_proprietaire(char *av);
void	ft_time(char *av);
char	**copy_argv(char **av, int nb, int ac); // copy argv sans opt
#endif
