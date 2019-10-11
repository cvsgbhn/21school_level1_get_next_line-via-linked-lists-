#include "get_next_line.h"

void ft_lstadd_toend_gnl(t_gnl **alst, t_gnl *new)
{
	int		length;

	while ((*alst)->next)
		length++;
	while (length-- > 0)
		*alst = (*alst)->next;
	(*alst)->next = new;
}

t_gnl	ft_check_fd(int intro_fd, char **line, t_gnl **text_list)
{
	int		flag;

	flag == 0;
	while ((*alst)->next)
	{
		if ((*alst)->fd == intro_fd)
		{
			//select this element to write there our text
			flag == 1;
		}
	}
	if (flag == 0)
	{
		ft_lstadd_toend_gnl(text_list, ft_lstnew(*line, ft_strlen(line)));
	}
	return (text_list);
}

int		get_next_line(const int fd, char **line)
{
	t_gnl		*text_list;
	static char	*ending;
	char		*ptr_to_end;
	int			num_read;

	return (1);
}
