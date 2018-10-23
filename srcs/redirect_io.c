#include "shell.h"


void	redirect_io(int fd_read, int fd_write)
{
	if (fd_read != STDIN)
	{
		close(0);
		if (dup(fd_read) == -1)
		{
			perror("21sh");
			exit(EXIT_FAILURE);
		}
		close(fd_read);
	}
	if (fd_write != STDOUT)
	{
		close(1);
		if (dup(fd_write) == -1)
		{
			perror("21sh");
			exit(EXIT_FAILURE);
		}
		close(fd_write);
	}
}
