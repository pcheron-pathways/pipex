/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:57:31 by pcheron           #+#    #+#             */
/*   Updated: 2023/02/23 14:34:02 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	main(int argc, char **argv, char **env)
{
	t_tab	*tab;
	int exit_status;

	if (argc < 5 || argc > 5)
		return (EXIT_FAILURE);
	tab = ft_make_tab(argc, argv, env);
	if (!tab)
		return (EXIT_FAILURE);
	exit_status = ft_pipex(tab, env);
	// printf("%s\n", ft_find_way(tab->env_path, tab->cmd[0][0]));
	// printab(tab);
	ft_free_tab(&tab);
	return (exit_status);
}
