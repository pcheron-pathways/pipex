/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:01:40 by pcheron           #+#    #+#             */
/*   Updated: 2023/03/09 18:42:03 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	ft_open_first_file(char *file1)
{
	int	fd;

	if (!ft_strncmp(file1, "here_doc", 9))
		return (-2); // replace by heredoc function
	if (access(file1, F_OK))
		return (-1); // pr
	if (access(file1, R_OK))
		return (-1); // print un truc
	fd = open(file1, O_RDONLY);
	if (fd > 0)
		return (fd);
	ft_print_fd(2, "no such file or directory: %s\n", file1);
	return (-1);
}

static int	ft_open_last_file(char *file2)
{
	// if (hd_status)	// replace by heredoc function
	// access(file2, X_OK); // care if file_out exist but you don't have rights
	return (open(file2, O_CREAT | O_RDWR | O_TRUNC, 0644)); // ! change les droits du fichier
	// return (open(file2, O_CREAT | O_RDWR | O_TRUNC, 0644));
}

int	*ft_build_fd(char **files)
{
	int	*fd;
	int	nb_file;

	nb_file = 2;
	fd = malloc(sizeof(int) * nb_file);
	if (!fd)
		return (NULL);
	fd[0] = ft_open_first_file(files[0]);
	// if (tab->fd[0] < 0)
	// 	return (127); //
	// printf("%d\n", tab->fd[0]);
	fd[1] = ft_open_last_file(files[1]);
	return (fd);
}

char	**ft_build_files(int argc, char **argv)
{
	char	**files;

	files = malloc(sizeof(char *) * 3);
	if (!files)
		return (NULL);
	files[0] = ft_strdup(argv[1]);
	if (!files[0])
		return (free(files), NULL);
	files[1] = ft_strdup(argv[argc - 1]);
	if (!files[1])
		return (free(files[0]), free(files), NULL);
	files[2] = NULL;
	return (files);
}
