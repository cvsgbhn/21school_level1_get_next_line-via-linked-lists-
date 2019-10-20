#include "get_next_line.h"

t_list	ft_check_fd(int intro_fd, char **line, t_list **text_list)
{
        if (fd < 0 || fd > 256)
          return (-1);
	while ((*alst)->next)
	{
		if ((*alst)->content_size == (size_t *)intro_fd)
		{
			return(text_list);
		}
	}
	ft_lstadd_toend(text_list, ft_lstnew(*line, ft_strlen(line)));
	return (text_list);
}

int		get_next_line(const int fd, char **line)
{
	static t_list		*text_list;
	char	*temp_array;
	char		buf[BUFF_SIZE + 1];
	char    *ptr_to_end;
	int     num_read;

	if (read(fd, NULL, 0) == -1)
	  return (-1);
	text_list = ft_check_fd(fd, line, text_list);
	while (!ptr_to_end && (num_read = read(fd, buf, BUFF_SIZE)))
        {
	  buf[num_read] = '\0';
	  if ((ptr_to_end = ft_strchr(buf, '\n')))
          {
	    *ptr_to_end = '\0';
	    ptr_to_end++;
	    text_list->content = ft_strdup(ptr_to_end);
          }
	   temp_array = *line;
	  *line = ft_strjoin(*line, buf);
	  free(temp_array);
        }
	if (!ft_strlen(*line))
        {
	  return ((!num_read && !ft_strlen(text_list->content)) ? 0 : 1);
        }
	else
          return (1);
}
