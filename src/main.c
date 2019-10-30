/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "fastatools.h"

int check_first_and_second(char *av)
{
    if (av[0] == '1' && first_fonction() == 84)
        return 84;
    if (av[0] == '2' && second_fonction() == 84)
        return 84;
    if (av[0] == '3' && third_fonction() == 84)
        return 84;
    return 0;
}

int check_fonction(char *av)
{
    if (av[0] < '1' || av[0] > '3' || av[0] == '4')
        return 84;
    else if (check_first_and_second(av) == 84)
        return 84;
    return 0;
}

int main(int ac, char **av)
{
    if (av[1] == NULL)
        return 84;
    if (ac > 3)
        return 84;
    if (strlen(av[1]) != 1)
        return 84;
    if (ac == 3 && !strcmp(av[1], "4"))
        fourth_fonction(atoi(av[2]));
    else if (ac == 2 && check_fonction(av[1]) == 0) {
        return 0;
    } else
        return 84;
    return 0;
}