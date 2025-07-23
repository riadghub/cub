/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:37:40 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/28 23:42:16 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_tokens(char const *s, char delimeter)
{
	size_t	tokens;
	int		inside_token;

	tokens = 0;
	while (*s)
	{
		inside_token = 0;
		while (*s == delimeter && *s)
			++s;
		while (*s != delimeter && *s)
		{
			if (!inside_token)
			{
				++tokens;
				inside_token = 1;
			}
			++s;
		}
	}
	return (tokens);
}

static int	safe_malloc(char **tokens_tab, int position, size_t buffer)
{
	int	i;

	i = 0;
	tokens_tab[position] = malloc(buffer);
	if (NULL == tokens_tab[position])
	{
		while (i < position)
			free(tokens_tab[i++]);
		free(tokens_tab);
		return (1);
	}
	return (0);
}

static int	fill(char **tokens_tab, char const *s, char delimeter)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == delimeter && *s)
			++s;
		while (*s != delimeter && *s)
		{
			++len;
			++s;
		}
		if (len)
		{
			if (safe_malloc(tokens_tab, i, len + 1))
				return (1);
			ft_strlcpy(tokens_tab[i], s - len, len + 1);
		}
		++i;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tokens_tab;
	size_t	tokens;

	if (s == NULL)
		return (NULL);
	tokens = count_tokens(s, c);
	tokens_tab = malloc((tokens + 1) * sizeof(char *));
	if (NULL == tokens_tab)
		return (NULL);
	tokens_tab[tokens] = NULL;
	if (fill(tokens_tab, s, c))
		return (NULL);
	return (tokens_tab);
}
/*
int	main(void)
{
	char	str[] = "test pour voir split !";
	char	c;
	char	**result;
	int		i;

	c = ' ';
	i = 0;
	result = ft_split(str, c);
	while (result[i] != NULL)
	{
		printf("Result after split de l'element %d : %s\n", i, result[i]);
		i++;
	}
}*/
