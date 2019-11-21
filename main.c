#include "get_next_line.h"

int		main(void) {
  char *line;
  int fd;
  //int a;

  fd = open("gnl11_1.txt", O_RDONLY);
  while ((get_next_line(fd, &line)) == 1)
  {
    printf("%s\n", line);
	free(line);
  }
  close(fd);
  return (0);
}

