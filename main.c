#include "get_next_line.h"

int		main(void)
{
	char 	*line;
	int 	fd;
	int		a;

	printf("%s\n", "fucksegfault");
	fd = open("test_file1", O_RDONLY);
	/*printf("%s\n", "fd - ok");
	a = get_next_line(fd, &line);
	printf("%s\n", "gnl - ok");
	printf("%s\n", line);  */
	while ((a = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
	}
	return (0);
}
