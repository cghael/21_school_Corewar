/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:19:32 by esnowpea          #+#    #+#             */
/*   Updated: 2020/12/03 14:43:11 by ablane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "asm_op.h"

typedef struct		s_car
{
	uint32_t		pos;
	char			*st;
	char			*end;
}					t_car;

void		print_result(t_player *win_player)
{
	ft_printf("Contestant %d, \"%s\", has won !", win_player->number,
		win_player->name);
	//TODO print_result
}

void		print_bit(uint8_t bit, char *st, char *end)
{
	char	a[] = "0123456789abcdef";

	ft_putstr(st);
	ft_putchar(a[bit / 16]);
	ft_putchar(a[bit % 16]);
	ft_putstr(end);
}

//void		vm_print_operation(t_carriage *car, t_vm *vm)
//{
//	ft_printf("P%5d | %s", car->number + 1, g_ops[car->operation - 1].name);
//	int i = 0;
//
//	while (i < g_ops[car->operation - 1].n_args)
//	{
//		if (car->args[i].type == T_REG)
//			ft_printf(" r%d", car->args[i].reg_nb);
//		else if (car->args[i].type == T_IND)
//			ft_printf(" %d", (int16_t)ft_bytetoint(
//					get_t_data(vm->arena, car->args[i].pos, MEM_SIZE),
//										  car->args[i].len));
//		else if (g_ops[car->operation - 1].t_dir_size == 4)
//			ft_printf(" %d",
//				ft_bytetoint(car->args[i].data, car->args[i].len));
//		else
//			ft_printf(" %d",
//				(int16_t)ft_bytetoint(car->args[i].data, car->args[i].len));
//		i++;
//	}
//	ft_printf("  [current = %6d]\n", vm->number_cycle);
//}

void		vm_print_arena(t_vm *vm)
{
	uint32_t	i;
	uint32_t	k;
	uint32_t	len;
	t_car		*car;
	t_list		*tmp;


	len = ft_lstlength(vm->carriages);
	car = (t_car*)ft_memalloc(sizeof(t_car) * len);
	ft_printf("\n[%d]\n", len);
	tmp = vm->carriages;
	i = 0;
	while (tmp)
	{
		car[i].pos = ((t_carriage*)tmp->content)->position;
		car[i].end = "\x1b[0m";
		if (((t_carriage*)tmp->content)->player->number == 1)
			car[i].st = "\x1b[46m"; //blue
		else if (((t_carriage*)tmp->content)->player->number == 2)
			car[i].st = "\x1b[43m"; //yellow
		else if (((t_carriage*)tmp->content)->player->number == 3)
			car[i].st = "\x1b[42m"; // green
		else if (((t_carriage*)tmp->content)->player->number == 4)
			car[i].st = "\x1b[41m"; // red
		i++;
		tmp = tmp->next;
	}
	i = 0;
	ft_printf("%6d : ", vm->number_cycle);
	int line = 64;
	while (i < MEM_SIZE)
	{
		k = 0;
		while (i != car[k].pos && k < len)
			k++;
		if (k < len)
			print_bit(vm->arena[i], car[k].st, car[k].end);
		else
			print_bit(vm->arena[i], "", "");
		if ((i + 1) % 64 == 0 && (i + 1) != MEM_SIZE)
		{
			ft_printf("\n%#5.4x : ", line);
			line += 64;
		}
		else
			ft_printf(" ");
		i++;
	}
	ft_printf("\n\n\n");
}
