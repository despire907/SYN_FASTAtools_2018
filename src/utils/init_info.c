/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#include "fastatools.h"

info_t *init_info(void)
{
    info_t *new = malloc(sizeof(info_t));

    new->name = NULL;
    new->adn = NULL;
    new->next = NULL;

    return new;
}

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= 'z' && str[i] >= 'a' )
            str[i] = str[i] - 32;
        ++i;
    }
    return (str);
}

char *check_string(char *str)
{
    int i = 0;
    int j = 0;
    char *tmp = malloc(sizeof(char) * (strlen(str) + 1));

    if (tmp == NULL)
        return NULL;
    tmp[strlen(str)] = '\0';
    while (str[i] != '\0') {
        if (str[i] != 'A' && str[i] != 'T' && str[i] != 'G' && str[i] != 'C' &&
        str[i] != 'N' && str[i] != ' ')
            i++;
        else {
            tmp[j] = str[i];
            j++;
            i++;
        }
    }
    free(str);
    return tmp;
}

char *check_adn(char **tab, int i)
{
    char *str = strdup("");
    int tmp = 0;

    while (tab[i] != NULL && tab[i][0] != '>') {
        str = realloc(str, (tmp + strlen(tab[i]) + 1));
        str[tmp + strlen(tab[i])] = '\0';
        tmp = tmp + strlen(tab[i]);
        strcat(str, tab[i]);
        i = i + 1;
    }
    str = my_strupcase(str);
    str = check_string(str);
    return str;
}

info_t *create_info(char **tab)
{
    int i = 0;
    info_t *new = init_info();
    info_t *begin = new;

    while (tab[i] != NULL) {
        if (tab[i][0] == '>') {
            new->name = tab[i];
            i++;
        } if (new->name != NULL)
            new->adn = check_adn(tab, i);
        if (new->name != NULL && new->adn != NULL && tab[i] != NULL) {
            new->next = init_info();
            new = new->next;
        }
        i++;
    }
    new = begin;
    return new;
}