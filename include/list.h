#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

#ifndef LIST_H
#define LIST_H

//structs for the options and info
typedef struct s_list
{
    char *file_Name;
    int file_Type;
    unsigned long long time_Sec;
    //unsigned long long time_Nano;
    struct s_list *next;
} t_list;

typedef struct opts_list
{
    bool opt_all;  // -a
    bool opt_time; // -t
} t_opts;

#endif

#ifndef UTILITY_C
#define UTILITY_C

t_opts *set_opts(int argc, char *argv[]);
t_list *new_node(t_list *ptr, char *file_Name, int file_Type, unsigned long long time_Sec/*, unsigned long long time_Nano*/);
t_list *node_swap(t_list *ptr1, t_list *ptr2);

void free_list(t_list *ptr);
void print_list(t_list *ptr);

int my_strcmp(char *ptr1, char *ptr2);
void alpha_sort(t_list **head, int file_counter);
void mod_time_sort(t_list **head, int file_counter);

#endif

// -----------------------

#ifndef MY_LS_C
#define MY_LS_C

void my_ls(t_opts *opts, char *dirname);

#endif


