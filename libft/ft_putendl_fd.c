/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:37:49 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/25 17:24:53 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s++, 1);
	}
	write(fd, "\n", 1);
}
/*
#include <fcntl.h>
int     main(void)
{
        int     fd = open("fd.txt", O_WRONLY | O_CREAT | O_TRUNC);
        if (fd == -1)
	{
		return (1);
	}
	ft_putendl_fd("Bonjour", fd);
	close(fd);
}
*/
