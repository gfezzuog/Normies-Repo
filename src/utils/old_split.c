/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:11:37 by sgerace           #+#    #+#             */
/*   Updated: 2023/03/29 05:12:24 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**old_fill_m(t_minishell **minip, char **matrix, t_old *old)
{
	t_xsubstr	sub;
	int			j;
	int			len;

	sub.i = 0;
	sub.len = 0;
	j = 0;
	while (j < old->num_w)
	{
		while (old->s[sub.i] == old->c)
			sub.i++;
		while (old->s[sub.i + sub.len] != old->c
			&& old->s[sub.i + sub.len] != '\0')
			sub.len++;
		if (sub.len != 0)
		{
			matrix[j] = ft_substr_m(&(*minip)->garbage, old->s, sub);
			matrix[j][ft_strlen(matrix[j])] = '\0';
			j++;
		}
		sub.i += sub.len;
	}
	return (matrix);
}

int	old_count_w(char *str, char c)
{
	int	num;
	int	toggle;

	num = 0;
	toggle = 0;
	while (*str)
	{
		if (*str != c && toggle == 0 && *str != '\0')
		{
			toggle = 1;
			num++;
		}
		else if (*str == c)
			toggle = 0;
		str++;
	}
	return (num);
}

t_old	*old_struct_create(void)
{
	t_old	*old;

	old = (t_old *)malloc(sizeof(t_old));
	old->num_w = 0;
	old->c = '\0';
	old->s = NULL;
	return (old);
}

char	**ft_old_split(t_minishell **minip, char const *s, char c)
{
	t_minishell	*mini;
	t_old		*old;
	char		**matrix;
	int			num_w;
	int			str_len;

	mini = *minip;
	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	num_w = old_count_w((char *)s, c);
	matrix = gc_alloc(&mini->garbage,
			(sizeof(char *) * (num_w + 1)), num_w + 1);
	if (!matrix)
		return (NULL);
	matrix[num_w] = NULL;
	old = old_struct_create();
	old->c = c;
	old->c = num_w;
	old->s = s;
	matrix = old_fill_m(minip, matrix, old);
	return (matrix);
}
