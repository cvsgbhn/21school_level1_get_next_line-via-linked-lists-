#include "get_next_line.h"

int		main(void)
{
	char 	*line;
	int 	fd;
	int		a;

	printf("%s\n", "fucksegfault");
	fd = open("animals_n1.mp4", O_RDONLY);
	while ((a = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
	}
	return (0);
}
