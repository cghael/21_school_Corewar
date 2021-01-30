/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablane <ablane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:38:48 by ablane            #+#    #+#             */
/*   Updated: 2021/01/30 12:12:41 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

t_list		*ft_lstpnew(void *content)
{
	t_list	*lstnew;

	if (!(lstnew = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	lstnew->content = content;
	lstnew->next = NULL;
	return (lstnew);
}

void		ft_lstpdelone(t_list **alst, t_list *del)
{
	t_list	*tmp;

	if (!alst || !(*alst) || !del)
		return ;
	if (*alst == del)
	{
		*alst = (*alst)->next;
		free(del->content);
		free(del);
		return ;
	}
	else
	{
		tmp = *alst;
		while (tmp->next && tmp->next != del)
			tmp = tmp->next;
		tmp->next = del->next;
		free(del->content);
		free(del);
		return ;
	}
}

u_int32_t	ft_lstlength(t_list *lst)
{
	t_list		*tmp;
	uint32_t	len;

	tmp = lst;
	len = 0;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int32_t		ft_bytetoint(const t_data arg, uint8_t len)
{
	int32_t		sum;
	uint32_t	k;

	sum = 0;
	k = 0;
	while (len)
	{
		len--;
		sum += arg.data[(arg.pos + len) % arg.max] << k;
		k += 8;
	}
	return (sum);
}

void		ft_inttobyte(const int32_t num, t_data arg, uint8_t len)
{
	uint32_t	k;

	k = 0;
	while (len)
	{
		len--;
		arg.data[(arg.pos + len) % arg.max] = (num >> k) & 0xFF;
		k += 8;
	}
}
