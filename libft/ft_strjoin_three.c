/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:51:10 by lsadi             #+#    #+#             */
/*   Updated: 2025/07/10 11:51:11 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_three(const char *s1, const char *s2, const char *s3)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_str_len(s1) + ft_str_len(s2) + ft_str_len(s3);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	i = 0;
	while (s3[i])
		res[j++] = s3[i++];
	res[j] = '\0';
	return (res);
}
