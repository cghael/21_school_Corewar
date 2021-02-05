/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:40:14 by ablane            #+#    #+#             */
/*   Updated: 2021/01/31 16:13:50 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	in_close_fd_err(int fd, char *err)
{
	if (close(fd) != 0)
		ft_dprintf(2, ERR_CLOSE_FILE);
	terminate(err);
}

void	terminate(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}

void	usage(void)
{
	ft_printf("Usage: ./corewar [\"-d N\" or \"-dump N\"| \"-n N\"| \"-a\"] "
		"<champion_name.cor> [-n N] <...> <...>\n[-dump N]\t: Dumps memory "
		"after N cycles, then exits (32 octets)\n[-d N] \t\t: Dumps memory "
		"after N cycles, then exits (64 octets)\n[-n N]\t\t: Sets the player to"
		" position N (N is the number of players participating in this game)"
		"\n[-a]\t\t: Prints output from \"aff\" (Default is to hide it)\n");
	exit(0);
}

void	err_flag(char c)
{
	if (c == 'd')
	{
		ft_dprintf(2, "Error: Use only -dump or -d with a number greater than"
				" zero (ex: ./corewar -dump 5 champion_name.cor)");
	}
	else if (c == 'n')
	{
		ft_dprintf(2, "Error: Use the -n flag with a number from 1 to N (N is "
			   "the number of players participating in this game) before the "
			"champion name (for example, 1: ./ corewar -n 3 champion-name.cor"
			" -n 2 champion-name 2.cor champion-name3 .cor)");
	}
	else if (c == 'a')
		ft_dprintf(2, "Error: The -a flag is used many times");
	else if (c == 'v')
		ft_dprintf(2, "Error: The -v flag is used many times");
	else if (c == 'u')
		usage();
	terminate("");
}
