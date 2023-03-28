/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:53:59 by manujime          #+#    #+#             */
/*   Updated: 2023/03/28 03:34:41 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_strings(char **strings) {
    int count = 0;
    while (*strings != NULL) {
        count++;
        strings++;
    }
    return (count);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **ft_parse(int argc, char **argv) {
    char **split_argv = malloc(argc * sizeof(char *));
    int split_argc = 0;
    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];
        char *arg_copy = strdup(arg); // make a copy of the argument string
        char *token = strtok(arg_copy, " ");
        while (token != NULL) {
            split_argv[split_argc++] = strdup(token);
            token = strtok(NULL, " ");
        }
        if (arg_copy[0] == '\0' || strspn(arg_copy, " ") == strlen(arg_copy)) {
            split_argv[split_argc++] = strdup("");
        }
        free(arg_copy); // free the memory allocated for the argument copy
    }
    for (int i = 0; i < split_argc; i++) {
        printf("%s ", split_argv[i]);
    }
    printf("\n");
    return(split_argv);
}


