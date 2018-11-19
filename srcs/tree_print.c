#include "shell.h"

char						*g_strtype[TOTAL_TYPE] = {
	[DEFAULT] = "default",
	[NEWLINE] = "newline",
	[IO_NUMBER] = "io_number",
	[TOKEN] = BLUE"token"RESET,
	[LESS] = PINK"less"RESET,
	[GREAT] = PINK"great"RESET,
	[DLESS] = PINK"dless"RESET,
	[DGREAT] = PINK"dgreat"RESET,
	[LESSAND] = PINK"lessand"RESET,
	[GREATAND] = PINK"greatand"RESET,
	[PIPELINE] = PINK"pipeline"RESET,
	[SEMICOLON] = RED"semicolon"RESET,
	[WORD] = BLUE"word"RESET
};

void	ast_print(t_ast **root)
{
	t_ast	*head;

	head = *root;
	if (!head)
		return ;
	if (head->left != NULL)
		ast_print(&head->left);
	ft_printf("%-20s > %s\n", g_strtype[head->token->type], head->token->literal);
	if (head->right != NULL)
		ast_print(&head->right);
}
