/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 08:48:44 by pcheron           #+#    #+#             */
/*   Updated: 2023/03/03 08:36:28 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_child(t_tab *tab, char **env, int i)
{
	pid_t	p_id;
	char	*path;

	p_id = fork();
	if (p_id == 0)
	{
		if (i == 0)
			dup2(tab->fd[0], STDIN_FILENO);
		else
			dup2(tab->pipes[i - 1][0], STDIN_FILENO);
		if (tab->cmd[i + 1])
			dup2(tab->pipes[i][1], STDOUT_FILENO);
		else
			dup2(tab->fd[1], STDOUT_FILENO);
		// path = ft_find_way(tab->env_path, tab->cmd[1][0]);
		// if (!path)
		// 	return(ft_free_tab(&tab), 127);
		// execve(path, tab->cmd[i], env);
	}
	return (p_id);
}

int	ft_pipex(t_tab *tab, char **env)
{
	pid_t	p_id;
	int		status;
	int		exit_status;
	int		i;

	i = 0;
	while (tab->cmd[i])
	{
		p_id = ft_child(tab, env, i);
		i++;
	}
	waitpid(p_id, &status, 0);
	if (!WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
		return (exit_status);
	}
	return (0);
}
