/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:32:23 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/21 22:16:36 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c -32);
	return (c);
}
/*
#include <stdio.h>
int	main(void)
{
	char c = 'a';
	printf("Avant  %c -> Apres : %c\n", c, ft_toupper(c));
	return (0);
}*/
