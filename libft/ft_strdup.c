/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:35:57 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/28 16:51:26 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		size;
	char	*dup;

	dup = 0;
	i = 0;
	size = ft_str_len(src);
	dup = malloc(sizeof(char) * (size + 1));
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// #include <stdio.h>
// int main(void)
// {
// 	char str1[] = "Une tres longue chaîne pour tester les capacites de strdup";
// 	char *dup1 = ft_strdup(NULL);
// 	if (dup1)
// 	{
// 	printf("TEST 1 :\n");
// 	printf("Chaine originale : \"%s\"\n", str1);
// 	printf("Chaine dupliquee : \"%s\"\n\n", dup1);
// 	free(dup1);
// 	}
// 	else
// 	{
// 	printf("TEST 1 : Erreur lors de la duplication\n\n");
// 	}
// 	char *dup2 = ft_strdup(NULL);
// 	if (dup2) 
// 	{
// 	printf("TEST 2 :\n");
// 	printf("Chaine originale : NULL\n");
// 	printf("Chaine dupliquee : \"%s\"\n\n", dup2);
// 	free(dup2);
// 	}
// 	else
// 	{
// 	printf("TEST 2 : Erreur lors de la duplication (NULL non géré)\n\n");
// 	}
// 	return (0);
// }
