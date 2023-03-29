/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:10:59 by dgioia            #+#    #+#             */
/*   Updated: 2023/03/29 04:32:56 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	g_exit_status;

int	ft_perror(int err, char *cmd)
{
	if (err == ERR_NCMD)
	{
		ft_printf("%s: Command not found!\n", cmd);
		//g_exit_status = 127;
	}
	if (err == ERR_QUOTE)
	{
		ft_printf("Double quotes not closed properly!\n");
		// g_exit_status = 127;
	}
	if (err == ERR_INPUT)
	{
		ft_printf("Character not valid!\n");
		// g_exit_status = 127;
	}
	return (1);
}
