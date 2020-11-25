/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:25:58 by ablane            #+#    #+#             */
/*   Updated: 2020/11/25 14:13:08 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_MALC_INIT		"ERROR: Can\'t initialize malloc"
# define ERR_MANY_CHAMP		"ERROR: Too many champions"
# define ERR_NUM_CHAMP		"ERROR: Invalid champion number"
# define ERR_BAD_FILE		"ERROR: Can\'t open file"
# define USAGE				"Usage: all info for CW"
# define ERR_BAD_MAGIC		"Error: File has an invalid header"
typedef						enum
{
	COMMON,
	DOUBLE_LABEL,
	TOO_MATCH_LABELS,
	LEXICAL_ERROR
}							t_errors;

static char				*g_error[] = {
		"something goes wrong :'(",
		"label with this name is already exist",
		"more then one label in line",
		"lexical error",
};

#endif //ERRORS_H
