//
// Created by  Anton Gorobets on 23.10.2020.
//

#ifndef ERRORS_H
# define ERRORS_H

typedef						enum
{
	COMMON,
	DOUBLE_LABEL,
	TOO_MATCH_LABELS,
	LEXICAL_ERROR,
	NO_SEPARATOR,
	FEW_ARGS,
}							t_errors;

static char					*g_error[] = {
		"something goes wrong :'(",
		"label with this name is already exist",
		"more then one label in line",
		"lexical error",
		"no separator char",
};

#endif //ERRORS_H
