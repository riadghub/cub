/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:37:05 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/24 20:41:28 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
/*
int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

#include <stdio.h>
int	main(void)
{
	int c;

	c = 'A';
	printf("test si alphanumerique OK('%c') = %d\n", c, ft_isalnum(c));
	c = '5';
        printf("test si alphanumerique OK('%c') = %d\n", c, ft_isalnum(c));
	c = '@';
        printf("test si alphanumerique NON '%c') = %d\n", c, ft_isalnum(c));
	c = 'z';
        printf("test si alphanumerique OK('%c') = %d\n", c, ft_isalnum(c));
	c = ' ';
	printf("test si alphanumerique NON('%c') = %d\n", c, ft_isalnum(c));
	return (0);
}*/
