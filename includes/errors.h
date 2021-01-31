/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:25:58 by ablane            #+#    #+#             */
/*   Updated: 2021/01/31 16:53:49 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_NO_CODE		"Error: No Code"
# define ERR_TO_BIGG		"Error: To big champion"
# define ERR_BAD_LEN		"Error: Wrong file size!!!"
# define ERR_BAD_FILE		"Error: Can\'t open file"
# define ERR_BAD_READ		"Error: Can\'t read file"
# define ERR_BAD_NAME		"Error: File has an invalid name"
# define ERR_BAD_COMM		"Error: File has an invalid comment"
# define ERR_BAD_MAGIC		"Error: File has an invalid header"
# define ERR_NUM_CHAMP		"Error: Invalid champion number"
# define ERR_MALC_INIT		"Error: Can\'t initialize malloc"
# define ERR_FEW_CHAMP		"Error: Too few champions"
# define ERR_MANY_CHAMP		"Error: Too many champions"
# define ERR_BAD_NULL_NAME	"Error: Missing NULL after champion's name"
# define ERR_BAD_NULL_COMM	"Error: Missing NULL after champion's comment"
# define ERR_CLOSE_FILE		"Error: close file"

typedef	enum
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
	NO_SUCH_LABEL,
	NO_NEWLINE,
	SYNTAX_ERROR,
	TOO_LONG,
	NO_OP
}	t_errors;

static char	*g_error[] = {
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
	"no such label",
	"no new line at the end of the file",
	"syntax error",
	"too long",
	"syntax error, no operations"
};

#endif
