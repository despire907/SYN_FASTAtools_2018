/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include <stdio.h>

int check_char(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
    (c >= 'a' && c <= 'z'))
        return 1;
    return 0;
}

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        ++i;
    }
    return str;
}

char *my_strcapitalize_synthesis(char *str)
{
    int i = 0;
    int check = 0;

    str = my_strlowcase(str);
    while (str[i] != '\0') {
        if ((str[i] >= '0' && str[i] <= '9') ||
        (str[i] >= 'A' && str[i] <= 'Z'))
            check = 0;
        else if (check == 0 && check_char(str[i - 1]) == 0)
            check = 1;
        if (str[i] >= 'a' && str[i] <= 'z' && check == 1) {
            str[i] = str[i] - 32;
            check = 0;
        }
        i++;
    }
    return str;
}