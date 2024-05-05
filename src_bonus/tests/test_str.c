
#include "ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	c;
    
    char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
    ft_printf("%s", "");
    ft_printf(" %s", "");
    ft_printf("%s ", "");
    ft_printf(" %s ", "");
    ft_printf(" %s ", "-");
    c = ft_printf(" %s %s ", "", "-");
    printf("\nMyCount%i\n", c);
    ft_printf(" %s %s ", " - ", "");
    ft_printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
    ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
    c = ft_printf(" NULL %s NULL ", NULL);
    printf("\nMyount%i\n", c);
    printf("\nPrintf standar\n");
    printf("%s", "");
    printf(" %s", "");
    printf("%s ", "");
    printf(" %s ", "");
    printf(" %s ", "-");
    c = printf(" %s %s ", "", "-");
    printf("\nCount%i\n", c);
    printf(" %s %s ", " - ", "");
    printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
    printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
    c = printf(" NULL %s NULL ", NULL);
    printf("\nCount%i\n", c);
}