/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:25:58 by ablane            #+#    #+#             */
/*   Updated: 2020/12/02 12:57:11 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define USAGE				"Usage: aLL iNfo foR CW"
# define ERR_BAD_LEN		"Error: Wrong file size!!!"
# define ERR_BAD_FILE		"ERROR: Can\'t open file"
# define ERR_BAD_READ		"ERROR: Can\'t read file"
# define ERR_BAD_NAME		"Error: File has an invalid name"
# define ERR_BAD_COMM		"Error: File has an invalid comment"
# define ERR_BAD_MAGIC		"Error: File has an invalid header"
# define ERR_NUM_CHAMP		"ERROR: Invalid champion number"
# define ERR_MALC_INIT		"ERROR: Can\'t initialize malloc"
# define ERR_MANY_CHAMP		"ERROR: Too many champions"
# define ERR_FEW_CHAMP		"ERROR: Too few champions"
# define ERR_BAD_NULL_NAME	"Error: Missing NULL after champion's name"
# define ERR_BAD_NULL_COMM	"Error: Missing NULL after champion's comment"

typedef						enum
{
	COMMON,
	DOUBLE_LABEL,
	TOO_MATCH_LABELS,
	LEXICAL_ERROR,
	NO_SEPARATOR,
	FEW_ARGS,
	WRONG_ARG_TYPE,
	INCORRECT_REG,
	INCORRECT_DIR,
	INCORRECT_IND,
	UNKNOWN_OPERATOR,
}							t_errors;

static char				*g_error[] = {
		"something goes wrong :'(",
		"label with this name is already exist",
		"more then one label in line",
		"lexical error",
		"no separator char",
		"wrong number of arguments",
		"wrong argument type",
		"incorrect register argument",
		"incorrect direct argument",
		"incorrect indirect argument",
		"incorrect operation name",
};

#endif //ERRORS_H
