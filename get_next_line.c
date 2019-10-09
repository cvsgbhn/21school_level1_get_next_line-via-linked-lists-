#include "get_next_line.h"

void	ft_list_content_tostr(char **line, t_list *text_list)
{
	while (text_list->next)
	{
		*line = ft_strjoin(*line, text_list->content);
		text_list = text_list->next;
	}
}

int		get_next_line(const int fd, char **line)
{
	t_list		*text_list;
	static char	*ending;
	char		*ptr_to_end;
	int			num_read;


	while (!ptr_to_end  && num_read = read(fd, buf, BUFF_SIZE))
	{
		buf[num_read] = '\0';
		if ((ptr_to_end = ft_strchr(buf, '\n')))
		{
			*ptr_to_end = '\0';
			ptr_to_end++;
			ending = ft_strdup(ptr_to_end);
		}
		ft_lstadd_toend(text_list, ft_lstnew(buf), (size_t) BUFF_SIZE));
	}
	ft_list_content_tostr(line, text_list);
	return (1);
}
