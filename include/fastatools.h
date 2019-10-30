/*
** EPITECH PROJECT, 2018
** task
** File description:
** task
*/

#ifndef SYN_FASTATOOLS_2018_FASTATOOLS_H
#define SYN_FASTATOOLS_2018_FASTATOOLS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info_s {
    char *name;
    char *adn;
    struct info_s *next;
}info_t;

int my_strlen_utils(char *str);
char *get_line(void);
char **get_file(void);
char **my_str_to_word_array_synthesis(char const *str);
info_t *create_info(char **tab);
int first_fonction(void);
int second_fonction(void);
int third_fonction(void);
int fourth_fonction(int k);
int my_cmp(const void *a, const void *b);
void k_mers_with_qsort(char **tab);
void free_tab(char **tab);
void free_info(info_t *info);

#endif //SYN_FASTATOOLS_2018_FASTATOOLS_H
