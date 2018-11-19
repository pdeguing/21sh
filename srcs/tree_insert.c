#include "shell.h"

static int	precedence_cmp(t_ast *new, t_ast *head)
{
	int		tnew;
	int		thead;

	tnew = new->token->type;
	thead = head->token->type;
//	ft_printf(RED"PRECEDENCE: "RESET"%d | vs | %d\n", thead, tnew);
	if (tnew == IO_NUMBER)
		tnew = LESS;
	if (IS_OP(tnew))
		tnew = LESS;
	if (IS_OP(thead) || thead == PIPELINE)
		thead = LESS;
	return (tnew - thead);
}

void		ast_insert(t_ast **root, t_ast *new)
{
	t_ast	*head;

	head = *root;
	if (head == NULL)
		*root = new;
	else if (precedence_cmp(new, head) >= 0 && new->token->type != TOKEN)
	{
		*root = new;
		new->left = head;
	}
	else if ((IS_OP(head->token->type) && head->right) || head->token->type == IO_NUMBER)
		ast_insert(&head->left, new);
	else
		ast_insert(&head->right, new);
}
