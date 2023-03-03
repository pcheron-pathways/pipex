/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:10:46 by pcheron           #+#    #+#             */
/*   Updated: 2023/03/03 15:00:57 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

// t_lst
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

// str1
int					ft_strlen(char *str);
int					ft_strslen(char **strs);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(char *s);
// str2
int					ft_instr(char const *str, char c);

// memory
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);

// strs
char				**ft_free_strs(char **strs, int j);
char				**ft_split(char const *s, char c);

// print
int					ft_putstr_fd(char *str, int fd);
int					ft_print_fd(int fd, char *str, ...);

// t_lst

#endif