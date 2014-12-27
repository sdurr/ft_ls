#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/17 09:02:37 by sdurr             #+#    #+#              #
#    Updated: 2014/12/19 18:14:04 by sdurr            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= ft_ls

SRC			= check_option_illegal.c \
				ft_ls_r_argv.c \
				ft_tab_blocks.c \
				ft_opt_l_uid_time.c \
				ft_no_files_or_directory.c \
				rm_tab_argv.c \
				test_directory.c \
				ft_rm_argv.c \
				ft_total_blocks.c \
				copy_argv.c \
				ft_count_sous_dossiers.c \
				ft_ls.c \
				ft_ls_argv.c \
				ft_ls_count_files.c \
				ft_ls_option_a.c \
				ft_ls_option_l.c \
				ft_ls_option_t.c \
				ft_ls_option_r.c \
				ft_noms_proprietaire.c \
				ft_print_tab.c \
				ft_time.c \
				ft_ls_path.c \
				main.c \
				test_option.c \
				test_files.c \
				ft_permission.c \

OBJ			= $(SRC:.c=.o)

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -rf

$(NAME)	:		$(OBJ)
				make -C libft
				$(CC) -o $(NAME) $(OBJ) -L libft/ -lft

clean	:
				$(RM) $(OBJ)

all		:		$(NAME)

fclean	:		clean
				$(RM) $(NAME)


re		:		fclean all

.c.o	:
				$(CC) $(CFLAGS) -I libft/includes/ -c $(SRC)
