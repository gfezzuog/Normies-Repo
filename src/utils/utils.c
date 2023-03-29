/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:29:08 by sgerace           #+#    #+#             */
/*   Updated: 2023/03/29 05:32:56 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_trypath(t_minishell **minip, char	*cmd, t_list **envp)
{
	t_list	*env;
	char	**trypath;
	char	*cmdcopy;
	int		i;

	i = 0;
	env = *envp;
	while (env)
	{
		if (!(ft_strncmp("PATH", env->key, 4)))
			trypath = ft_old_split(minip, env->value, ':');
		i++;
		env = env->next;
	}
	cmdcopy = cmd;
	i = 0;
	while (trypath[i])
	{
		trypath[i] = ft_strjoin(trypath[i], "/", 0);
		cmd = ft_strjoin(trypath[i], cmd, 0);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		else
			cmd = cmdcopy;
		i++;
	}
	return (NULL);
}

void	ft_clean_all(t_minishell **minip)
{
	t_minishell	*mini;

	mini = *minip;
	free_stuff(NULL, NULL, &mini->envp_list);
	free_stuff(NULL, NULL, &mini->cmd_list);
	free_stuff(NULL, NULL, &mini->envp_list);
}

int	free_stuff(t_list *node, char **matrix, t_list **stack)
{
	int	i;

	i = 0;
	if (node != NULL)
	{
		free(node);
		node = NULL;
	}
	if (matrix != NULL)
	{
		while (matrix[i])
			free(matrix[i++]);
		free(matrix);
		matrix = NULL;
	}
	if (stack != NULL)
		ft_lst_delete(stack);
	return (0);
}

void	ft_lst_delete(t_list **stack)
{
	t_list	*tmp;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free (*stack);
		*stack = tmp;
	}
}

size_t	ft_smaller_string(char *str1, char *str2)
{
	if (ft_strlen(str1) > ft_strlen(str2))
		return (ft_strlen(str2));
	else
		return (ft_strlen(str1));
}
