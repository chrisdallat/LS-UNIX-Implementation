#include "../include/list.h"

int main(int argc, char **argv)
{
    t_opts *opts = set_opts(argc, argv);
    int i = 1;

    for (i = 1; i < argc; i++)
    {
        if ((argv[i][0] == '-' && (argv[i][1] != 'a' && argv[i][1] != 't')))
        {
            printf("Error! Option Not Available\n");
            return (1);
        }
    }

    if (argc == 1 || (argc == 2 && argv[1][0] == '-') || (argc == 3 && argv[1][0] == '-' && argv[2][0] == '-'))
    {
        my_ls(opts, ".");
    }
    else
    {
        i = 1;
        while (i < argc)
        {

            if (argv[i][0] != '-')
            {
                char *dirpath = malloc(50); //reinitialize each loop
                strcpy(dirpath, "./");
                strcat(dirpath, argv[i]);
                if (argc > 2)
                {
                    printf("%s:\n", argv[i]);
                }

                my_ls(opts, dirpath);
                if (i < (argc - 1)) //to replicate docodes format
                {
                    printf("\n");
                }
                free(dirpath);
            }

            i++;
        }
    }
    return 0;
}