
#include <sys/stat.h>
#include "libft.h"

void   ft_tab_blocks(char **tab, int count)
{
     struct stat sb;
     int c;

     c = 0;
     count = count + 1;
     if (count > 1)

     while (tab[count] && (ft_strchr(tab[count], ':')) != NULL)
     {
	  stat(tab[count], &sb);
	  c = c + sb.st_blocks;
	  count++;
     }
     ft_putstr("total ");
     ft_putnbr(c);
     ft_putchar('\n');
}
