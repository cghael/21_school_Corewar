/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:40:14 by ablane            #+#    #+#             */
/*   Updated: 2021/01/15 12:40:14 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	in_close_fd_err(int fd, char *err)
{
	close(fd);
	terminate(err);
}

void	terminate(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}
