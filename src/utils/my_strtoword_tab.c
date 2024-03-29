/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "fastatools.h"

int alpha_num(char car)
{
    if ((car >= '0' && car <= '9') || (car >= 'a' && car <= 'z') ||
        (car >= 'A' && car <= 'Z')  || (car == '>') || (car == ',') ||
        (car == ' ') || (car == '|') || (car == '.') || (car == '_') ||
        (car == ')') || car == '(')
        return 1;
    else
        return 0;
}

int count_char(char const *str, int i)
{
    while (alpha_num(str[i]) == 1) {
        i++;
    }
    return i;
}

int count_word(char const *str)
{
    int i = 0;
    int k = 0;

    while (str[i] != '\0') {
        if (i > 0 && alpha_num(str[i]) == 0 && alpha_num(str[i - 1]) == 1)
            k++;
        i++;
    }
    return k;
}

void check_loop(int *i, int *j, int *k, char const *str)
{
    if (*i > 0 && alpha_num(str[*i]) == 0 && alpha_num(str[*i - 1]) == 1) {
        *i = *i + 1;
        *j = *j + 1;
        *k = 0;
    }
}

char **my_str_to_word_array_synthesis(char const *str)
{
    char **tab = NULL;
    int i = 0;
    int j = 0;
    int k = 0;

    if ((tab = malloc(sizeof(char *) * (count_word(str) + 2))) == NULL)
        return NULL;
    while (str[i] != '\0') {
        check_loop(&i, &j, &k, str);
        if ((tab[j] = malloc(sizeof(char) * (count_char(str, i) + 1))) == NULL)
            return NULL;
        while (str[i] != '\0' && alpha_num(str[i]) == 1) {
            tab[j][k] = str[i];
            k++;
            i++;
        }
        tab[j][k] = '\0';
    }
    tab[j + 1] = NULL;
    return tab;
}