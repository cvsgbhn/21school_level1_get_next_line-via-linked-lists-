/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:29:13 by vdanilo           #+#    #+#             */
/*   Updated: 2019/11/21 20:23:55 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_copy_content(char **line, char *content, char c)
{
	int		counter;

	counter = 0;
	while (content[counter] && content[counter] != c)
		counter++;
	if (!(*line = ft_strndup(content, counter)))
		return (-1);
	return (counter);
}

int		ft_reading(const int fd, char **line)
{
	int		fd_read;
	char	*tmp_str;
	char	buf[BUFF_SIZE + 1];

	while ((fd_read = read(fd, buf, BUFF_SIZE)))
	{
		buf[fd_read] = '\0';
		tmp_str = *line;
		if (!(*line = ft_strjoin(tmp_str, buf)))
			return (-1);
		free(tmp_str);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (fd_read);
}

t_list	*ft_check_fd(int fd, t_list **static_list)
{
	t_list *tmp_lst;
	t_list *lst;

	if (!*static_list)
		return (*static_list = ft_lstnew("\0", fd));
	lst = *static_list;
	while (lst && (int)lst->content_size != fd)
	{
		tmp_lst = lst;
		lst = lst->next;
	}
	if (!lst)
	{
		lst = ft_lstnew("\0", fd);
		tmp_lst->next = lst;
	}
	return (lst);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*static_list;
	t_list			*temp_list;
	size_t			fd_read;
	char			*t_content;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || (!(temp_list = ft_check_fd(fd, &static_list))) ||
			(read(fd, buf, 0)) < 0)
		return (-1);
	t_content = temp_list->content;
	fd_read = ft_reading(fd, &t_content);
	temp_list->content = t_content;
	if (!fd_read && !*t_content)
		return (0);
	fd_read = ft_copy_content(line, temp_list->content, '\n');
	t_content = temp_list->content;
	if (t_content[fd_read] != '\0')
	{
		temp_list->content = ft_strdup(&((temp_list->content)[fd_read + 1]));
		free(t_content);
	}
	else
		t_content[0] = '\0';
	return (1);
}
