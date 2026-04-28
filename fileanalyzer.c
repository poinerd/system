#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    
    // Step 1: Check input
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char *filepath = argv[1];

    // Step 2: Get file metadata
    struct stat fileStat;

    if (stat(filepath, &fileStat) != 0) {
        perror("Error");
        return 1;
    }

    // Step 3: Determine file type
    char *fileType;
    if (S_ISREG(fileStat.st_mode)) {
        fileType = "Regular file";
    } else if (S_ISDIR(fileStat.st_mode)) {
        fileType = "Directory";
    } else {
        fileType = "Other";
    }

    // Step 4: Open file (only if regular file)
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Step 5: Count lines, words, characters
    int lines = 0;
    int words = 0;
    int chars = 0;
    int inWord = 0;

    char ch;

    while ((ch = fgetc(file)) != EOF) {
        chars++;

        if (ch == '\n') {
            lines++;
        }

        if (ch == ' ' || ch == '\n' || ch == '\t') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            words++;
        }
    }

    fclose(file);

    // Step 6: Output results
    printf("File: %s\n", filepath);
    printf("Type: %s\n", fileType);
    printf("Size: %ld bytes\n", fileStat.st_size);
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", chars);

    return 0;
}