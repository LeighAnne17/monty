#include "monty.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    char *file_path = argv[1];


    FILE *file = fopen(file_path, "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", file_path);
        return EXIT_FAILURE;
    }

    fclose(file);
    return EXIT_SUCCESS;
}
