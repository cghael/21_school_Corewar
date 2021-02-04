//
// Created by Karina Semele on 2/3/21.
//

#include "corewar.h"
#include "asm_op.h"
#include <ncurses.h>
//#define PLAYER_1		1
#define BIT_PAIR		02

static void ft_vi_print_bit(uint8_t bit, short color)
{
	char		*a;

	a = "0123456789abcdef";
	start_color();			/* Start color 			*/
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);

	if (bit != 0)
	{
		attron(COLOR_PAIR(color));
		addch(a[bit / 16] | A_BOLD);
		addch(a[bit % 16] | A_BOLD);
		attroff(COLOR_PAIR(color));
//		addch(a[bit / 16] | A_BOLD | A_STANDOUT);
//		addch(a[bit % 16] | A_BOLD | A_STANDOUT);
	}
	else
	{
//		use_default_colors();
		addch(a[bit / 16]);
		addch(a[bit % 16]);
	}
//	printw("%c", a[bit % 16]);
}

static void		ft_vi_print_arena(t_vm *vm)
{
	uint32_t	i;
	uint32_t	line;
	uint32_t	length;
	short			color;

	i = 0;
	color = 1;
	printw("%6s : ", "0x0000");
	if (vm->flag.d)
		length = 64;
	if (vm->flag.dump)
		length = 32;
	line = length;
	while (i < MEM_SIZE)
	{
		ft_vi_print_bit(vm->arena[i].byte, color);
		if ((i + 1) % length == 0 && (i + 1) != MEM_SIZE)
		{
			printw(" \n%#5.4x : ", line);
			line += length;
		}
		else
			printw(" ");
		i++;
		color++;
		if (color > 5)
			color = 1;
	}
	printw("\n");
}

int		ft_visualiser(t_vm *vm)
{
	if (vm->flag.v)
	{
		vm->flag.d = 1;
		vm->flag.dump = 0;
		initscr();
		curs_set(0);
//		raw();
		keypad(stdscr, true);
		refresh();

		while (true)
		{
			clear();
			ft_vi_print_arena(vm);
			//Получаем нажатие пользователя
			if (getch() == KEY_RIGHT)
				printw("KEY RIGHT!\n");
			if (getch() == KEY_ENTER)
				break ;
		}
		endwin();
		ft_printf("FLAG V!\n");//todo del
	}
	return (0);
}