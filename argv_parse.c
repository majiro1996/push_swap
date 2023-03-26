/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:53:59 by manujime          #+#    #+#             */
/*   Updated: 2023/03/24 17:03:37 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "push_swap.h"

char** parse_args(char **argv, int argc) {
    char **result = malloc(sizeof(char*) * (argc - 1));
    int i, j;
    char *word, *start, *end;

    for (i = 1, j = 0; i < argc; i++) {
        start = trim_left(argv[i]);
        while (*start) {
            end = find_next_space(start);
            word = malloc(end - start + 1);
            strncpy(word, start, end - start);
            word[end - start] = '\0';
            result[j++] = word;
            start = find_next_word(end);
        }
    }
    return result;
}

int count_words(char *str) {
    int count = 0;
    char *p = trim_left(str);
    while (*p) {
        p = find_next_space(p);
        count++;
        if (!*p) {
            break;
        }
        p = find_next_word(p);
    }
    return count;
}

char* find_next_word(char *str) {
    while (*str && *str == ' ') {
        str++;
    }
    return str;
}

char* find_next_space(char *str) {
    while (*str && *str != ' ') {
        str++;
    }
    return str;
}

char* trim_left(char *str) {
    while (*str && *str == ' ') {
        str++;
    }
    return str;
}

int main(int argc, char **argv) {
    char **result = parse_args(argv, argc);
    int i, n = argc - 1;
    for (i = 0; i < n; i++) {
        printf("result[%d] == \"%s\"\n", i, result[i]);
    }

    for (i = 0; i < n; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
