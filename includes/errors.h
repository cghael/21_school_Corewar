//
// Created by  Anton Gorobets on 23.10.2020.
//

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_MALC_INIT		"ERROR: Can\'t initialize malloc"
# define ERR_GNL_READ		"ERROR: Can\'t read gnl"

typedef						enum
{
	COMMON,
	DOUBLE_LABEL,
	TOO_MATCH_LABELS,
	LEXICAL_ERROR
}							t_errors;

static char					*g_error[] = {
		"something goes wrong :'(",
		"label with this name is already exist",
		"more then one label in line",
		"lexical error",
};

#endif //ERRORS_H
