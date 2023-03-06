
#include "../include/libft.h"

int	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return (0);
	return (write(fd, str, ft_strlen(str)));
}
