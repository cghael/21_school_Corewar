//
// Created by  Anton Gorobets on 23.10.2020.
//
#include "asm.h"

char		*ft_strjoin_n_free(char *s1, char *s2)
{
	char *tmp;

	tmp = s1;
	if (s1 == NULL)
		return (s2);
	s1 = ft_strjoin(s1, s2);
	free(tmp);
	free(s2);
	return (s1);
}
