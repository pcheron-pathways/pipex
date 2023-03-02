/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:34:22 by pcheron           #+#    #+#             */
/*   Updated: 2023/03/02 14:34:40 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// tab

typedef struct s_tab
{
	int		hd_status;
	int		nb_pipes;
	int		nb_fd;
	char	**env_path;
	char	**files;
	int		*fd;
	int		**pipes;
	char	***cmd;
}			t_tab;

// tab
// t_tab		*ft_make_tab(int argc, char **argv, char **env);
// char		*ft_find_way(char **path, char *cmd);
// void		ft_free_tab(t_tab **tab);

// files
// char		**ft_build_files(int argc, char **argv);
// int			*ft_build_fd(char **files);
// pipes
// int			ft_pipex(t_tab *tab, char **env);
// int			**ft_build_pipes(int nbr);
// void		ft_free_pipes(int nbr, int **pipes);
// void		ft_close_pipes(int nbr, int **pipes);

// exec ans status
ft_return_status(pid_t last_pid, int wstatus);

#endif
