/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:33:35 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/21 20:40:57 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	int c;

	c = 'A';
	printf("test si alphabetique OK('%c') = %d\n", c, ft_isalpha(c));
	c = '5';
        printf("test si alphabetique NON('%c') = %d\n", c, ft_isalpha(c));
	c = '@';
        printf("test si alphabetique NON '%c') = %d\n", c, ft_isalpha(c));
	c = 'z';
        printf("test si alphabetique OK('%c') = %d\n", c, ft_isalpha(c));
	c = ' ';
	printf("test si alphabetique NON('%c') = %d\n", c, ft_isalpha(c));
	return (0);
}*/
