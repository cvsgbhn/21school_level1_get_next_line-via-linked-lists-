/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:29:13 by vdanilo           #+#    #+#             */
/*   Updated: 2019/10/27 18:45:18 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_copy_content(char **line, char *content, char c)
{
	int		counter;
	//char	*tmp;

	counter = 0;
	//tmp = *line;
	while (content[counter] && content[counter] != c)
		counter++;
	if (!(*line = ft_strndup(content, counter)))
		return (0);
	free(content);
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
		if (!(*line = ft_strjoin(*line, buf)))
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

	if (!static_list)
		return (NULL);
	tmp_lst = *static_list;
	while (tmp_lst)
	{
		if ((int)(tmp_lst->content_size) == fd)
			return (tmp_lst);
		tmp_lst = tmp_lst->next;
	}
	tmp_lst = ft_lstnew("", fd);
	ft_lstadd(static_list, tmp_lst);
	return (tmp_lst);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*static_list;
	t_list			*temp_list;
	size_t			fd_read;
	char			*t_content;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || (!(temp_list = ft_check_fd(fd, &static_list)))||
			(read(fd, buf, 0)) < 0)
	{
	    //free(temp_list);
        return (-1);
	}
	t_content = temp_list->content;
	fd_read = ft_reading(fd, &t_content);
	temp_list->content = t_content;
	if (!fd_read && !*t_content)
    {
	    free (t_content);
	    return (0);
    }
	fd_read = ft_copy_content(line, temp_list->content, '\n');
	t_content = temp_list->content;
	if (t_content[fd_read] != '\0')
	{
	  temp_list->content = ft_strdup(&((temp_list->content)[fd_read + 1]));
	  free(t_content);
	}
	else {
          t_content[0] = '\0';
          free(temp_list->content);
        }
	free(t_content);

	return (1);
}