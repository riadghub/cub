/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:34:15 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/25 17:00:08 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_str_len(s1);
	while (s1[start] && ft_str_chr(set, s1[start]))
		start++;
	while (end > start && ft_str_chr(set, s1[end - 1]))
		end --;
	result = (char *)malloc((end - start + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (start < end)
	{
		result[i] = s1[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	char *s1 = "  Bonjour,  merci!  ";
	char *set = "  ";
	char *result;

	result = ft_strtrim(s1, set);
	if (result)
	{
		printf("chaine originale : \%s\"\n", s1);
		printf("set : \"%s\"\n", set);
		printf("chaine trimme :\%s\"\n", result);
		free(result);
	}
	else
	{
		printf("erreur d'execution \n");
	}
	return (0);
}*/
