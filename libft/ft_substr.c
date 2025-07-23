/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:32:07 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/21 14:25:56 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_str_len(s))
		return (ft_strdup(""));
	if (len > ft_str_len(s) - start)
		len = ft_str_len(s) - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
int main(void)
{
    char *str = "Bonbon, chocolat !";
    char *result;
    
    result = ft_substr(str, 0, 7);
    if (result)
    {
        printf("Test 1 sous chaine au debut : \n");
        printf("Chaîne originale : \"%s\"\n", str);
        printf("Sous-chaîne (start = 0, len = 7) : \"%s\n", result);
        printf("\n");
	free(result);
    }

    result = ft_substr(str, 8, 10);
    if (result)
    {
        printf("Test 2 sous chaine au milieu :\n");
        printf("Chaîne originale : \"%s\"\n", str);
        printf("Sous-chaîne (start = 8, len = 10) : \"%s\n", result);
        free(result);
    }
    return (0);
}
*/
