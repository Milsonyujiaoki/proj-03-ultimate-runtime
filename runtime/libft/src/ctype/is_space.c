#include "../../include/ctype.h"

int ft_isspace(int ch)
{
    return (ch == ' ' || ch == '\t' || ch == '\n' ||
            ch == '\v' || ch == '\f' || ch == '\r');
}