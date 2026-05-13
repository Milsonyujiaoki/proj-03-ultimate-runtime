#include "../../include/ctype.h"

int ft_isgraph(int ch)
{
    return (ch >= 33 && ch <= 126);
}