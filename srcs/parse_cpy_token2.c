#include "../includes/minishell.h"

int single_quote(t_minishell *mini, char *src, char **dest, int *src_move)
{
    if (unclosed(&src[*src_move], '\''))
        *src_move += single_cpy(&src[*src_move], dest);
    else
    {
        mini->error = 1;
        return (0);
    }
    return (1);
}

int double_quote(t_minishell *mini, char *src, char **dest, int *src_move)
{
    if (unclosed(&src[*src_move], '\"'))
        *src_move += double_cpy(&src[*src_move], dest, mini);
    else
    {
        mini->error = 1;
        return (0);
    }
    return (1);
}