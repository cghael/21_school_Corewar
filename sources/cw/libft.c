//
// Created by esnowpea on 27.11.2020.
//

#include "libft.h"

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
		free(del);
		return ;
	}
	else
	{
		tmp = *alst;
		while (tmp->next && tmp->next != del)
			tmp = tmp->next;
		tmp->next = del->next;
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

int32_t		ft_bitetoint(uint8_t const arg[], uint8_t len)
{
	int32_t		sum;
	uint32_t	k;

	sum = 0;
	k = 1;
	while (len)
	{
		len--;
		sum += arg[len] * k;
		k *= 256;
	}
	return (sum);
}
