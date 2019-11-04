#include "libft.h"

char	*ft_strndup(const char *s1, size_t num)
{
  char	*s2;
  size_t	i;

  i = 0;
  if (!(s2 = ft_strnew(num)))
    return (NULL);
  while (s1[i] && i < num)
  {
    s2[i] = s1[i];
    i++;
  }
  return (s2);
}
