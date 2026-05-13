#include "../../include/ctype.h"

int ft_ispunct(int ch)
{
    return (ft_isgraph(ch) && !ft_isalnum(ch));
}