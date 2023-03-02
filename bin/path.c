/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:54:11 by pcheron           #+#    #+#             */
/*   Updated: 2023/02/22 10:41:47 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_build_path(char *folder, char *cmd)
{
	char	*path;
	int		i;
	int		j;

	path = malloc(ft_strlen(folder) + ft_strlen(cmd) + 2);
	if (!path)
		return (NULL);
	i = -1;
	while (folder[++i])
		path[i] = folder[i];
	j = i;
	path[j] = '/';
	j++;
	i = -1;
	while (cmd[++i])
		path[j + i] = cmd[i];
	path[i + j] = 0;
	return (path);
}

char	*ft_find_way(char **path, char *cmd)
{
	int		i;
	char	*way;

	i = -1;
	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	if (!path)
		return (NULL);
	while (path[++i])
	{
		way = ft_build_path(path[i], cmd);
		if (!way)
			return (NULL);
		else if (access(way, F_OK | X_OK) == 0)
			return (way);
		else
			free(way);
	}
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	return (NULL);
}
