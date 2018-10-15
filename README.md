# 21sh
You’ll have to start from your minishell and make it stronger to get little by littler closer to a real functionnal shell. You’ll add couple of features such as multi-commande management, redirections as well as line edition that will allow you to use arrows for example.

## Allowed functions:

*	malloc, free
*	access
*	open, close, read, write
*	opendir, readdir, closedir
*	getcwd, chdir
*	stat, lstat, fstat
*	fork, execve
*	wait, waitpid, wait3, wait4
*	signal, kill
*	exit
*	pipe
*	dup, dup2
*	isatty, ttyname, ttyslot
*	ioctl
*	getenv
*	tcsetattr, tcgetattr
*	tgetent
*	tgetflag
*	tgetnum
*	tgetstr
*	tgoto
*	tputs

## Requirements:

- [ ] line edition
- [ ] ctl+D and ctl+C for line edition and process execution
- [ ] multiple commands with ';'
- [ ] pipes with '|'
- [ ] redirections '<', '>', '<<' and '>>'
- [ ] file descriptor aggregation
- [ ] history
- [ ] cut/copy/paste
- [ ] move from word to word
- [ ] move to beginning or end of line
- [ ] write and edit command over a few lines
- [ ] manage quotes and doubles quotes, even on several lines (expansions excluded)

## Bonus:

- [ ] search through history
- [ ] hash table for binary files
- [ ] tab completion
- [ ] vim binding mode freely activable
- [ ] syntactic shell coloration freely activable
