/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:29:41 by pcheron           #+#    #+#             */
/*   Updated: 2023/03/03 15:05:11 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// Create an array of nbr malloc'ed pipes
// Return 1 if a malloc error is encountered
int	**ft_build_pipes(int nbr)
{
	int	i;
	int	**pipes;

	pipes = malloc(sizeof(int *) * nbr);
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < nbr)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (!pipes[i])
		{
			ft_close_pipes(i, pipes);
			ft_free_pipes(i, pipes);
			return (NULL);
		}
		if (pipe(pipes[i]) < 0)
		{
			ft_close_pipes(i, pipes);
			ft_free_pipes(i + 1, pipes);
			return (NULL);
		}
		i++;
	}
	return (pipes);
}

// Free an array of n malloc'ed pipes
void	ft_free_pipes(int nbr, int **pipes)
{
	int	i;

	i = 0;
	if (pipes)
	{
		while (i < nbr)
		{
			free(pipes[i]);
			i++;
		}
	}
	free(pipes);
}

// Close an array of n pipes
void	ft_close_pipes(int nbr, int **pipes)
{
	int	i;

	i = 0;
	if (pipes)
	{
		while (i < nbr)
		{
			if (pipes[i])
			{
				if (close(pipes[i][0]) < 0)
					perror("close pipe");
				if (close(pipes[i][1]) < 0)
					perror("close pipe");
			}
			i++;
		}
	}
}
