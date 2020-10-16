//
// Created by  Anton Gorobets on 14.10.2020.
//
#include "asm.h"

/*
** Return	-1	if there is no \" in line or any other not whitespace symbol
** 			0	if there is only open \"
** 			1	if there are open and close \"
*/

static int	ft_looking_for_name(char *line, t_asm *asm_s)
{
	int	i;
	int	open;
	int	close;

	i = 0;
	open = 0;
	close = 0;
	while (line[i])
	{
		if (!ft_is_whitespace(line[i]))
		{
			if (line[i] == '"' && !open)
				open = i;
			else if (line[i] == '"' && open)
				close = i;
			else if (open && close && line[i] == '#')
				break ;
			else
				return (-1);
		}
		i++;
	}
	if (open && close)
		return (1);
	else if (open)
		return (0);
	return (-1);
}

int			ft_parse_name(char *line, t_asm *asm_s)
{
	char	*tmp;
	int		res;

	res = ft_looking_for_name(line, asm_s);
	if (res == ERR_NO_NAME)
		return (ERR_NO_NAME);
	if (res == FULL_NAME)
		return (FULL_NAME);
//	while ((res = ft_get_next_line(asm_s->fd, &tmp)) > 0)
//	{
//
//	}
//	if (res < 0)
//		//todo error
//	return (EXIT_SUCCESS);
	return (FULL_NAME);
}

//Champion name too long (Max length 128)