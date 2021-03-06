
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:33:10 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/04 10:06:06 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_LS_H
# define	FT_LS_H

# define OPT_L 4
# define OPT_A 8
# define OPT_T 16
# define OPT_R 32
# define OPT_R_R 64
# define OPT_R_S 128

char	**ft_ls(char **argv); // s'il n'y a pas d'argv en parametre
char	**recursive(char *tab_argv);
char	**ft_ls_argv(char **argv, int argc, int nb_argv, char ***tab_argv);
int		check_option_illegal(char *argv); // check quel option et renvoi vers la fonction
void    ft_tab_blocks(char **tab, int count);
char    **ft_ls_r_argv(char **tab);
char    **ft_ls_r(char **tab);
char	**ft_ls_option_a(char **argv, int argc, int nb); // option -a
void	ft_ls_option_l(char **tab); //option -l
void	ft_opt_l_uid_time(char **tab, int count, int c);
char	**ft_ls_option_r(char **tab); // option -r
char	**ft_ls_option_r_r(char **tab_argv, char **tab); // option -r
char	**ft_ls_option_t(char **tab, int i, int j, char **tab_old); // option -t
char	**ft_ls_t_argv(char **tab);
char	**ft_no_files_or_directory(char **argv, int j, char ***tab_argv);
void	ft_permission(char *tab);
void	ft_total_blocks(char **tab);
void	rm_tab_argv(char ***argv, int i);
int		ft_count_sous_dossiers(char *tab); // count le nom de dossier dans un dossier
int		ft_ls_count_files(char **argv); // conte le nb de fichier dossiers
int		ft_ls_count_files_R(char **argv, int nb_argv, int argc); //conte nb files dock and sous files
char	**ft_rm_argv(char **argv, int i);
int		test_option(char **argv, int *nb, int i, int j); // test options with bitwise
char 	*test_files(char *argv);
char	**ft_ls_path(char **tab_argv, char **tab);
int		open_file(char *path);
char	*test_directory(char *tab);
void	ft_print_tab(char **tab);
void	ft_noms_proprietaire(char *av);
void	ft_time(char *av);
char	**copy_argv(char **av, int nb, int ac); // copy argv sans opt
char	**copy_argv_2(char **av, int nb);
#endif
