/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:32:12 by gfezzuog          #+#    #+#             */
/*   Updated: 2023/03/29 05:32:12 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_free_stuff(t_minishell *mini, char *str)
{
	if (str)
		free(str);
	if (mini)
		free(mini);
	return ;
}

t_minishell	*ft_get_mini(t_minishell *mini)
{
	static t_minishell	*mini_s;

	if (mini != NULL)
	{
		mini_s = mini;
	}
	return (mini_s);
}

int	ft_strerr(char *str)
{
	int	i;

	i = 0;
	write(1, str, ft_strlen(str));
	return (1);
}

int	ft_count_commands(t_list **cmd_list)
{
	t_list	*head;
	int		i;

	i = 0;
	head = *cmd_list;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

int	ft_count_rows(char **cmd_m)
{
	int	i;

	i = 0;
	while (cmd_m[i])
	{
		i++;
	}
	return (i);
}
