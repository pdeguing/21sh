#include "parsing.h"

void	tree_print(t_tree **root)
{
	t_tree	*head;

	head = *root;
	if (head->left != NULL)
		tree_print(&head->left);
	ft_printf("%-20s > %s\n", g_strtype[head->token->type], head->token->literal);
	if (head->right != NULL)
		tree_print(&head->right);
}
