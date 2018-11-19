#include "shell.h"

t_ast		*ast_new(t_token *token)
{
	t_ast	*new;

	new = (t_ast *)malloc(sizeof(t_ast));
	if (new == NULL)
		return (NULL);
	new->token = token;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
