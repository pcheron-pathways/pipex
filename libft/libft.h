/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:10:46 by pcheron           #+#    #+#             */
/*   Updated: 2023/02/22 11:10:47 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

// str
int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_putstr_fd(char *str, int fd);
char	*ft_strdup(char *s);

// memory
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);

// strs
char	**ft_free_strs(char **strs, int j);
char	**ft_split(char const *s, char c);

#endif