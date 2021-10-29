#include "../include/list.h"

t_opts *set_opts(int argc, char *argv[])
{
    int i = 1, j = 0;
    t_opts *opts = malloc(sizeof(t_opts));
    opts->opt_all = false;
    opts->opt_time = false;
    while (i < argc)
    {
        j = 0;
        if (argv[i][j] == '-')
        {
            j++;
            while (argv[i][j] != '\0')
            {

                if (argv[i][j] == 'a')
                    opts->opt_all = true;
                else if (argv[i][j] == 't')
                    opts->opt_time = true;
                else
                {
                    printf("Error, option -%c not available!\n", argv[i][j]);
                    return opts;
                }
                j++;
            }
        }
        i++;
    }
    return opts;
}

t_list *new_node(t_list *ptr, char *file_Name, int file_Type, unsigned long long time_Sec/*, unsigned long long time_Nano*/)
{
    t_list *new_node;

    new_node = malloc(sizeof(t_list));

    new_node->file_Name = file_Name;
    new_node->file_Type = file_Type;
    new_node->time_Sec = time_Sec;
    //new_node->time_Nano = time_Nano;
    new_node->next = ptr;
    return new_node;
}

t_list *node_swap(t_list *ptr1, t_list *ptr2)
{
    t_list *temp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = temp;
    return ptr2;
}

void free_list(t_list *ptr)
{
    t_list *temp;

    while (ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
}

void print_list(t_list *ptr)
{
    t_list *temp = ptr;

    if (!temp)
        printf("list is empty");
    while (temp)
    {
        printf("%s  ", temp->file_Name);
        temp = temp->next;
    }
    printf("\n");
}



int my_strcmp(char *ptr1, char *ptr2)
{
    int i = 0;
    while ((ptr1[i] != '\0') || (ptr2[i] != '\0'))
    {
        if (ptr1[i] > ptr2[i])
            return 1;
        if (ptr1[i] < ptr2[i])
            return -1;
        i++;
    }

    return 0;
}

void alpha_sort(t_list **head, int file_counter)
{
    t_list **h;
    int i, j, swapped;

    i = 0;
    while (i <= file_counter)
    {
        h = head;
        swapped = 0;
        j = 0;
        while (j < file_counter - i - 1)
        {
            t_list *ptr1 = *h;
            t_list *ptr2 = ptr1->next;

            if (my_strcmp(ptr1->file_Name, ptr2->file_Name) == 1)
            {
                *h = node_swap(ptr1, ptr2);
                swapped = 1;
            }
            h = &(*h)->next;
            j++;
        }
        if (swapped == 0)
            break;
        i++;
    }
}

void mod_time_sort(t_list **head, int file_counter)
{
    t_list **h;
    int i, j, swapped;

    i = 0;
    while (i <= file_counter)
    {
        h = head;
        swapped = 0;
        j = 0;
        while (j < file_counter - i - 1)
        {
            t_list *ptr1 = *h;
            t_list *ptr2 = ptr1->next;
            if (ptr1->time_Sec < ptr2->time_Sec)
            {
                *h = node_swap(ptr1, ptr2);
                swapped = 1;
            }
            /*else if (ptr1->time_Sec == ptr2->time_Sec)
            {
                if (ptr1->time_Nano < ptr2->time_Nano)
                {
                    *h = node_swap(ptr1, ptr2);
                }
                else if (ptr1->time_Nano == ptr2->time_Nano)
                {
                    if (my_strcmp(ptr1->file_Name, ptr2->file_Name) == 1)
                    {
                        *h = node_swap(ptr1, ptr2);
                    }
                }
                swapped = 1;
            }
            */
            h = &(*h)->next;
            j++;
        }
        
        if (swapped == 0)
            break;
        i++;
    }
}