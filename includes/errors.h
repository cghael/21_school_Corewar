/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:25:58 by ablane            #+#    #+#             */
/*   Updated: 2021/01/30 18:46:46 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define USAGE0				"Usage: ./corewar [\"-d N\" or \"-dump N\"| "
# define USAGE1				"\"-v\"| \"-n N\"| \"-a\"] <champion_name.cor> "
# define USAGE2				"[-n N] <...> <...>\n[-dump N]\t: Dumps memory "
# define USAGE3				"after N cycles, then exits 32 octets\n[-d N] "
# define USAGE4				"\t\t: Dumps memory after N cycles, then exits 64"
# define USAGE5				" octets\n[-v]\t\t: Visualization of the "
# define USAGE6				"game\n[-n N]\t\t: Sets the player to position N "
# define USAGE7				"(N is the number of players participating in "
# define USAGE8				"this game)\n[-a]\t\t: Prints output from \"aff\""
# define USAGE9				" (Default is to hide it)\n"
# define ERR_DUMP			"Error: Use only -dump or -d with a number greater than zero (ex: ./corewar -dump 5 champion_name.cor)"
# define ERR_FLAG			"Error: Use the flag (-dump, -d, -v, -a) after the \"corvar\" (ex1:./corewar -dump 5 -a champion_name.cor, ex2:./corewar -v -d 12 champion_name.cor)"
# define ERR_FLAG_N			"Error: Use the -n flag with a number from 1 to N (N is the number of players participating in this game) before the champion name (for example, 1: ./ corewar -n 3 champion-name.cor -n 2 champion-name 2.cor champion-name3 .cor)"
# define ERR_FLAG_V			"Error: The -v flag is used many times"
# define ERR_FLAG_A			"Error: The -a flag is used many times"
# define ERR_BAD_LEN		"Error: Wrong file size!!!"
# define ERR_CODE_LEN		"Error: Player code is too long"
# define ERR_BAD_FILE		"Error: Can\'t open file"
# define ERR_BAD_READ		"Error: Can\'t read file"
# define ERR_BAD_NAME		"Error: File has an invalid name"
# define ERR_BAD_COMM		"Error: File has an invalid comment"
# define ERR_BAD_MAGIC		"Error: File has an invalid header"
# define ERR_NUM_CHAMP		"Error: Invalid champion number"
# define ERR_MALC_INIT		"Error: Can\'t initialize malloc"
# define ERR_MANY_CHAMP		"Error: Too many champions"
# define ERR_FEW_CHAMP		"Error: Too few champions"
# define ERR_BAD_NULL_NAME	"Error: Missing NULL after champion's name"
# define ERR_BAD_NULL_COMM	"Error: Missing NULL after champion's comment"
# define ERR_CLOSE_FILE		"Error: close file"

# define PLAYERS			"-n 2 /Users/ablane/Desktop/vm_champs/ex.cor /Users/ablane/Desktop/vm_champs/ultima.cor /Users/ablane/Desktop/vm_champs/Explosive_Kitty.cor /Users/ablane/Desktop/vm_champs/katchup.cor"
//todo KILL STR*

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
