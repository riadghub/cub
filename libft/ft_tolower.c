/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:32:08 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/21 22:18:27 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c +32);
	return (c);
}
/*
#include <stdio.h>
int	main(void)
{
	char c = 'A';
	printf("Avant : %c -> Apres : %c\n", c, ft_tolower(c));
	return (0);
}
*/
