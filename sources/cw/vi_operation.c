#include "corewar.h"
#include "asm.h"
# include <ncurses.h>

t_player		*vi_operation(t_vm *vm)
{
	uint32_t current;
//	int input;

	current = 0;
	ft_visualiser(vm);
	while ((vm->vi->button = getch()) != ESC)
	{
		vi_handle_buttons(vm);
		if (vm->vi->is_running)
		{
			while (vm->carriages)
			{
				vm_survey_carriages(vm);//todo draw is here
				current++;
				vm->number_cycle++;
				if (vm->cycles_to_die <= 0 ||
					current == (uint32_t) vm->cycles_to_die)
				{
					vm->number_checks++;
					current = 0;
					vm_checkout(vm);
				}
			}
		}
	}
	endwin();
	return (vm->last_live_player);
}