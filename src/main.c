/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:57:31 by pcheron           #+#    #+#             */
/*   Updated: 2023/03/03 08:41:04 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// void	printab(t_tab *tab)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	printf("----- env path -----\n");
// 	while (tab->env_path[++i])
// 		printf("%s\n", tab->env_path[i]);
// 	printf("----- files -----\n");
// 	printf("fd1 :%d\nfd2 :%d\n", tab->fd[0], tab->fd[1]);
// 	printf("f1 :%s\nf2 :%s\n", tab->files[0], tab->files[1]);
// 	printf("----- pipes -----\n");
// 	i = -1;
// 	while (++i < tab->nb_pipes)
// 		printf("%d : %d\n", tab->pipes[i][0], tab->pipes[i][1]);
// 	printf("----- cmds -----\n");
// 	i = -1;
// 	while (tab->cmd[++i])
// 	{
// 		j = -1;
// 		printf("- commands %d -\n", i);
// 		while (tab->cmd[i][++j])
// 			printf("%s\n", tab->cmd[i][j]);
// 	}
// }

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

int	ft_return_status(pid_t last_pid, int wstatus)
{
	pid_t	wpid;
	int		return_status;
	int		return_value;

	while (true)
	{
		wpid = wait(&wstatus);
		if (wpid < 0)
			break ;
		if (wpid == last_pid)
		{
			if (WIFEXITED(wstatus))
				return_value = WEXITSTATUS(wstatus);
			else
				return_value = 128 + WTERMSIG(wstatus);
		}
	}
	return (return_value);
}

int	main(int argc, char **argv, char **env)
{
	t_tab	*tab;
	int		exit_status;
	pid_t	last_pid;
	int		i;

	if (argc != 5)
		return (EXIT_FAILURE); // print syntax : ./pipex file1 cmd1 cmd2 file2
	tab = ft_make_tab(argc, argv, env);
	if (!tab)
		return (EXIT_FAILURE); // print allocation failed
	// printf("%s\n", ft_find_way(tab->env_path, tab->cmd[0][0]));
	// printab(tab);
	i = -1;
	while (tab->cmd[++i])
		last_pid = ft_child(tab, env, i);
	ft_free_tab(&tab);
	return (ft_return_status(last_pid, wstatus));
}
