/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:40:54 by sgerace           #+#    #+#             */
/*   Updated: 2023/03/25 14:34:53 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/minishell.h"

char	*ft_strdup_m(t_garbage **garbage, const char *s1)
{
	size_t	dim;
	char	*stack;

	if (s1 == NULL)
		return (NULL);
	dim = ft_strlen(s1) + 1;
	//stack = (char *) malloc(sizeof(char) * dim);
	stack = gc_alloc(garbage, (sizeof(char) * dim), dim);
	if (s1 == NULL)
		return (NULL);
	else
		ft_memcpy(stack, s1, dim);
	return (stack);
}
