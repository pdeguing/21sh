#include "shell.h"

char	*g_builtin_name[BUILTIN_NBR] =
{
	"echo",
	"cd",
	"env",
	"setenv",
	"unsetenv",
	"exit",
};

int		(*g_builtin_func[BUILTIN_NBR])(char **) =
{
	&builtin_echo,
	&builtin_cd,
	&builtin_env,
	&builtin_setenv,
	&builtin_unsetenv,
	&builtin_exit,
};

void		exe_cmd(char **args, char flag, t_io **io_stack)
{
	int		i;

	if (args == NULL || args[0] == NULL)
		return ;
	i = 0;
	if (!ft_strchr(args[0], '/'))
	{
		while (i < BUILTIN_NBR)
		{
			if (ft_strcmp(args[0], g_builtin_name[i]) == 0)
			{
				io_redirect(io_stack);
				g_builtin_func[i](args + 1);
				return ;
			}
			i++;
		}
	}
	exe_bin(args, flag, io_stack);
}
