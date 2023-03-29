/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_variant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:22:51 by gfezzuog          #+#    #+#             */
/*   Updated: 2023/03/29 05:22:51 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**ft_split_variant(t_minishell *mini, char *s)
{
	char		**matrix;
	char		c[3];
	t_xfillmv	*fmv;

	fmv = gc_alloc(&mini->garbage, sizeof(t_xfillmv), 0);
	ft_init_fmv(fmv);
	c[0] = '|';
	c[1] = '>';
	c[2] = '<';
	if (!s)
		return (NULL);
	fmv->num_w = count_wv((char *)s, c, 0, 0);
	matrix = gc_alloc(&mini->garbage,
			(sizeof(char *) * (fmv->num_w + 1)), fmv->num_w + 1);
	if (!matrix)
		return (NULL);
	matrix[fmv->num_w] = NULL;
	matrix = fill_mv(mini, fmv, s, matrix);
	return (matrix);
}
