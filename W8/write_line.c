#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LENGTH 8192

int main(int argc, char *argv[]) {
    // This program should only run for argc == 2
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }
    // and which reads a line from stdin, 
    // and writes it to the specified file
    // if the file exists, it should be overwritten.
    char line[MAX_LENGTH];
    if (fgets(line, MAX_LENGTH, stdin) == NULL) {
        perror("");
        exit(1);
    }

    FILE *out = fopen(argv[1], "w");
    if (out == NULL) {
        perror("");
        exit(1);
    }

    fputs(line, out);
    fclose(out);

    return 0;
}