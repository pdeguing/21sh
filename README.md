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

-----------------------

## Shell Command Language

### Token Recognition

1. If the end of input is recognized, the current token shall be delimited. If
there is no current token, the end-of-input indicator shall be returned as the
token.
2. If the previous character was used as part of an operator and the current
character is not quoted and can be used with the current characters to form an
operator, it shall be used as part of that (operator) token.
3. If the previous character was used as part of an operator and the current
character cannot be used with the current characters to form an operator, the
operator containing the previous character shall be delimited.
4. If the current charcter is backslash, single-quote, or double-quote and it is
not quoted, it shall affect quoting for subsequent characters up to the end of 
the quoted text. During token recognition no substitutions shall be actually
performed, and the result token shall contain exactly the characters that appear
in the input (except for <newline> joining), unmodified, including any embedded
or enclosing quotes or substitution operators, between the quote mark and the
end of the quoted text. The token shall not be delimited by the end of the quoted
field.
5. If the current character is an unquoted '$' or '`', the shell shall identify
the start of any candidates for parameter expansion, command substitution, or
arithmetic expansion from their introductory unquoted character sequences.The
shell shall read sufficient input to determine the end of the unit to be expanded.
While processing the characters, if instances of expansions or quoting are found
nested withint the substituton, the shell shall recursively process them in the
manner specified fot the construt that is found. The characters found from the
beginning of the substitution to its end, allowing for any recursion necessary
to recognize embedded constructs, shall be included unmodified in the result
tolken, including any embedded or enclosing substitution operators or quotes.
The token shall not be delimited by the end of the substitution.
6. If the current character is not quoted and can be used as the first
character of a new operatorm the current token (if any) shall be delimited.
The current character shall be used as the beginning of the next (operator) token.
7. If the current character is an unquoted <newline>, the current token shall
be delimited.
8. If the current character is an unquoted <blank>, any token containing the
previous character is delimited and the current character shall be discarded.
9. If the previous character was part of a workd, the current character shall be
appended to that word.
10. If the current character is a '#', it and all subsequent characters up to,
but excluding, the next <newline> shall be discarded as a comment. The
<newline> that ends the line is not considered part fo the comment.
11. The current character is used as the start of a new word.
