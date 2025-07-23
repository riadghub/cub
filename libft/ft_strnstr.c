/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:16:02 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/21 21:54:32 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	const char big1[] = "bonjour, merci";
	const char little1[] = "merci";
	char *result1 = ft_strnstr(big1, little1, 15);

	if (result1)
		printf("TEST 1 resultat : %s\n", result1);
	else
		printf("TEST 1 resultat : NULL\n");
	
	const char big2[] = "bonjour ";
        const char little2[] = "merci";
        char *result2 = ft_strnstr(big2, little2, 15);

        if (result2)
                printf("TEST 2 resultat : %s\n", result2);
        else
                printf("TEST 2 resultat : NULL\n");
}
*/
