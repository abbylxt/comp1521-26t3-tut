#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LENGTH 8192

int main(int argc, char *argv[]) {
    // This program should only run for argc == 2
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }
    // which is given one command-line argument, the name of a file, 
    // and which prints the first line of that file to stdout.
    
    FILE *in = fopen(argv[1], "r");
    if (in == NULL) {
        perror("");
        exit(1);
    }
    char line[MAX_LENGTH];
    if (fgets(line, MAX_LENGTH, in) == NULL){
        printf("empty file\n");
    } else {
        fputs(line, stdout);
    }

    fclose(in);

    return 0;
}