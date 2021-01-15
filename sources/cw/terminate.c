
#include "corewar.h"

void	in_close_fd_err(int fd, char *err)
{
	close(fd);
	terminate(err);
}

void	terminate(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);

}
