#include "libft.h"

char	*ft_strndup(const char *s1, size_t num)
{
  char	*copy;

  if ((copy = ft_strnew(num)))
    return(ft_strncpy(copy, s1, num));
  else
  {
    free(copy);
    return (NULL);
  }
}
