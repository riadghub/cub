/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:14:45 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/20 22:16:57 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_str_join(char const *s1, char const *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_str_len(s1);
	len2 = ft_str_len(s2);
	result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < len1)
		result[i] = s1[i];
	j = 0;
	while (j < len2)
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>
int main(void)
{
    char *s1 = "Bonjour, ";
    char *s2 = "merci !";
    char *result;

    result = ft_strjoin(s1, s2);
    if (result)
    {
        printf("s1: \"%s\"\n", s1);
        printf("s2: \"%s\"\n", s2);
        printf("Résultat: \"%s\"\n", result);
        free(result);
    }
    else
    {
        printf("Erreur : strjoin a retourné NULL.\n");
    }

    s1 = "";
    s2 = "Chaîne non vide";
    result = ft_strjoin(s1, s2);
    if (result) 
    {
        printf("\nTest avec s1 vide :\n");
        printf("s1: \"%s\"\n", s1);
        printf("s2: \"%s\"\n", s2);
        printf("Résultat: \"%s\"\n", result);
        free(result);
    }
    else
    {
        printf("Erreur : strjoin a retourne NULL.\n");
    }

    s1 = NULL;
    s2 = "Chaîne non vide";
    result = ft_strjoin(s1, s2);
    if (result) 
    {
        printf("\nTest avec s1 NULL :\n");
        printf("Résultat: \"%s\"\n", result);
        free(result);
    }
    else
    {
        printf("Erreur : strjoin a retourne NULL.\n");
    }

    return (0);
}*/
