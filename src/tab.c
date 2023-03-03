/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:40:43 by pcheron           #+#    #+#             */
/*   Updated: 2023/03/03 12:28:48 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	**ft_build_env_path(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (ft_split(env[i] + 5, ':'));
	// if env == NULL, test chemin absolue + bonne valeur de retour
	return (NULL);
}

static char	***ft_build_cmd_tab(int argc, char **argv)
{
	char	***cmd;
	int		i;
	int		j;

	i = 0;
	cmd = malloc(sizeof(char **) * (argc - 2));
	if (!cmd)
		return (NULL);
	while (i < argc - 3)
	{
		cmd[i] = ft_split(argv[i + 2], ' ');
		if (!cmd[i])
		{
			while (--i > -1)
			{
				j = 0;
				while (cmd[i][j])
					j++;
				ft_free_strs(cmd[i], j);
			}
			return (free(cmd), NULL);
		}
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}

static t_tab	*ft_make_tab2(t_tab *tab, int argc, char **argv, char **env)
{
	int	i;

	i = 0;
	while (tab->env_path[i])
		i++;
	tab->files = ft_build_files(argc, argv);
	if (!tab->files)
		return (ft_free_strs(tab->env_path, i), free(tab), NULL);
	tab->fd = ft_build_fd(tab->files);
	if (!tab->fd)
		return (ft_free_strs(tab->files, 2), ft_free_strs(tab->env_path, i),
			free(tab), NULL);
	tab->pipes = ft_build_pipes(tab->nb_pipes);
	if (!tab->pipes)
		return (free(tab->fd), ft_free_strs(tab->files, 2),
			ft_free_strs(tab->env_path, i), free(tab), NULL);
	tab->cmd = ft_build_cmd_tab(argc, argv);
	if (!tab->cmd)
		return (ft_free_pipes(2, tab->pipes), free(tab->fd),
			ft_free_strs(tab->files, 2), ft_free_strs(tab->env_path, i),
			free(tab), NULL);
	return (tab);
}

t_tab	*ft_make_tab(int argc, char **argv, char **env)
{
	t_tab			*tab;
	unsigned int	nb_file;
	unsigned int	nb_cmd;

	nb_file = 2;
	nb_cmd = argc - 3;
	tab = malloc(sizeof(t_tab));
	if (!tab)
		return (NULL);
	tab->hd_status = 0;
	tab->nb_pipes = nb_cmd - 1;
	tab->nb_fd = 2;
	tab->env_path = ft_build_env_path(env);
	if (!tab->env_path)
		return (free(tab), NULL); // wtf
	return (ft_make_tab2(tab, argc, argv, env));
}

void	ft_free_tab(t_tab **tab)
{
	int	i;
	int	j;

	i = -1;
	while ((*tab)->cmd[++i])
	{
		j = 0;
		while ((*tab)->cmd[i][j])
			j++;
		ft_free_strs((*tab)->cmd[i], j);
	}
	free((*tab)->cmd);
	ft_close_pipes(1, (*tab)->pipes);
	ft_free_pipes(1, (*tab)->pipes);
	free((*tab)->fd);
	ft_free_strs((*tab)->files, 2);
	i = 0;
	while ((*tab)->env_path[i])
		i++;
	ft_free_strs((*tab)->env_path, i);
	free(*tab);
	*tab = NULL;
}
