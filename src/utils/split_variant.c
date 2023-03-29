/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_variant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:01:20 by sgerace           #+#    #+#             */
/*   Updated: 2023/03/29 05:23:30 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_init_fmv(t_xfillmv *fmv)
{
	fmv->i = 0;
	fmv->j = 0;
	fmv->len = 0;
	fmv->qcount = 0;
	fmv->quotes = 0;
	fmv->num_w = 0;
	fmv->c = 0;
}

int	ft_get_word_length(const char *s, t_xfillmv *fmv)
{
	int	len;

	len = 0;
	while (s[fmv->i + len] != '\0')
	{
		if (s[fmv->i + len] == 34 || s[fmv->i + len] == 39)
		{
			fmv->quotes = ft_is_escaped(s[fmv->i + len], 0);
			if (fmv->quotes > 0)
				fmv->qcount++;
			else if (fmv->quotes < 0)
				fmv->qcount--;
		}
		if (ft_char_red(s[fmv->i + len]) && fmv->qcount == 0)
		{
			if (ft_char_red(s[fmv->i + len + 1]))
				len++;
			break ;
		}
		len++;
	}
	return (len + 1);
}

char	**fill_mv(t_minishell *mini, t_xfillmv *f, const char *s, char **m)
{
	t_xsubstr	sub;

	while (f->j < f->num_w)
	{
		while (ft_char_red(s[f->i]))
				f->i++;
		f->len = ft_get_word_length(s, f);
		if (f->len != 0)
		{
			while (s[f->i] == ' ')
			{
				s++;
				f->len--;
			}
			sub.i = f->i;
			sub.len = f->len;
			m[f->j] = ft_substr_m(&mini->garbage, s, sub);
			f->j++;
		}
		f->i += f->len;
		f->len = 0;
	}
	return (m);
}

int	ft_update_quotes(char c)
{
	int	quotes;

	quotes = ft_is_escaped(c, 0);
	if (quotes > 0)
		return (1);
	else if (quotes < 0)
		return (-1);
	return (0);
}

int	count_wv(char *str, char *c, int toggle, int num)
{
	int	qcount;

	qcount = 0;
	while (*str)
	{
		if (*str == 34 || *str == 39)
			qcount += ft_update_quotes(*str);
		if ((*str != c[0] || *str != c[1] || *str != c[2]) \
			&& toggle == 0 && *str != '\0')
		{
			toggle = 1;
			num++;
		}
		else if ((*str == c[0] || *str == c[1] || *str == c[2]) && qcount == 0)
			toggle = 0;
		str++;
	}
	return (num);
}
