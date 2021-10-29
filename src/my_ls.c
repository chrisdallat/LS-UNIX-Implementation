#include "../include/list.h"

void my_ls(t_opts *opts, char *dirname)
{
    t_list *ptr = NULL;
    struct dirent *sd;
    struct stat file_info;
    DIR *dir;

    int counter = 0;
    unsigned long long seconds;
    //unsigned long long nseconds;
    dir = opendir(dirname);

    while ((sd = readdir(dir)) != NULL)
    {
        if ((my_strcmp(sd->d_name, ".") == 0 || my_strcmp(sd->d_name, "..") == 0) && opts->opt_all == false)
            continue;
        else
        {
            lstat(sd->d_name, &file_info);
            seconds = (unsigned long long)file_info.st_mtime;  //for IDE used in course
            //nseconds = (unsigned long long)file_info.st_mtim.tv_nsec; //use st_mtimespec elsewise
            ptr = new_node(ptr, sd->d_name, sd->d_type, seconds/*, nseconds*/);
            counter++;
        }
    }

    if (opts->opt_time == true)
        mod_time_sort(&ptr, counter);
    else
        alpha_sort(&ptr, counter);

    print_list(ptr);
    free_list(ptr);
}
