/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:10:13 by cghael            #+#    #+#             */
/*   Updated: 2019/10/09 16:27:07 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function check static list->content_size node by node.
** Returns ptr to node, if content_size == fd, or return NULL.
*/

static t_list	*ft_find_fd(t_list **st_list, const int fd)
{
	t_list *fd_node;

	fd_node = *st_list;
	if (!fd_node)
		return (NULL);
	while (fd_node)
	{
		if (fd_node->content_size == (size_t)fd)
			return (fd_node);
		fd_node = fd_node->next;
	}
	return (NULL);
}

/*
** Function use ft_find_fd() to find node that content buf from fd
** Then it searchs \n in it. If there is no \n function will return NULL
** or it will return ptr to \n of this node->content.
*/

static char		*ft_static_check(t_list **st_list, const int fd)
{
	t_list	*fd_node;
	char	*tmp;

	if (!*st_list)
		return (NULL);
	fd_node = ft_find_fd(st_list, fd);
	if (!fd_node)
		return (NULL);
	tmp = ft_strchr((char*)fd_node->content, '\n');
	return (tmp);
}

/*
** Puts buf into static list node.
** If there is no node with content_size == fd, creates it.
*/

static int		ft_static_fill(t_list **st_list, char *buf, const int fd)
{
	t_list	*fd_node;
	char	*tmp;

	if ((fd_node = ft_find_fd(st_list, fd)))
	{
		if (!(tmp = ft_strjoin((char*)fd_node->content, buf)))
			return ((int)ft_node_del(st_list, fd_node, (void*)(-1)));
		free(fd_node->content);
		fd_node->content = tmp;
	}
	else
	{
		if (!(fd_node = ft_lstnew(NULL, 0)))
			return (-1);
		fd_node->content_size = fd;
		if (!(fd_node->content = ft_strdup(buf)))
		{
			free(fd_node);
			return (-1);
		}
		ft_lstaddend(st_list, fd_node);
	}
	return (0);
}

/*
** Puts static into line. Returns (-1) if smth goes wrong, (0) if res == 0
** and there is nothing in static (and free mem), and (1) if
** there is smth left in static.
*/

static int		ft_put_line(char **line, t_list **st_list, \
							const int fd, t_list *fd_node)
{
	char	*n_ptr;
	char	*tmp;

	if ((n_ptr = ft_static_check(st_list, fd)))
	{
		if (!(*line = ft_strsub((char*)fd_node->content, 0, \
					ft_strlen((char*)fd_node->content) - ft_strlen(n_ptr))))
			return (-1);
		tmp = fd_node->content;
		if (!(fd_node->content = ft_strdup(n_ptr + 1)))
			return (-1);
		free(tmp);
		return (1);
	}
	else if (fd_node && *(char*)(fd_node->content))
	{
		if (!(*line = ft_strdup((char*)fd_node->content)))
			return (-1);
		return ((int)ft_node_del(st_list, fd_node, (void*)1));
	}
	*line = NULL;
	return ((int)ft_node_del(st_list, fd_node, (void*)0));
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_list	*st_list;
	char			*n_ptr;
	ssize_t			res;
	char			buf[BUFF_SIZE + 1];
	t_list			*fd_node;

	if ((res = read(fd, buf, 0)) < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	n_ptr = ft_static_check(&st_list, fd);
	while (!n_ptr && (res = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[res] = '\0';
		if (ft_static_fill(&st_list, buf, fd) < 0)
			return (-1);
		n_ptr = ft_static_check(&st_list, fd);
	}
	fd_node = ft_find_fd(&st_list, fd);
	if (res < 0)
		return ((int)ft_node_del(&st_list, fd_node, (void*)(-1)));
	res = ft_put_line(line, &st_list, fd, fd_node);
	if (res < 0)
		ft_node_del(&st_list, fd_node, (void*)(-1));
	return (res);
}
