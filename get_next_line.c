#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	t_list		*text_list;
	static char *ending;
	char 		*ptr_to_end;

	if ((ptr_to_end = ft_strchr(*line, '\n')))
	{
		ptr_to_end = '\0';
		ft_lstadd (text_list, ft_lstnew(*line, (size_t)BUFF_SIZE));
	}
	return (1);
}
