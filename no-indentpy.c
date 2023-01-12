#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file.py>\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE* in_file = fopen(argv[1], "r");
    if (in_file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    // Open the output file
    char out_file_name[100];
    snprintf(out_file_name, sizeof(out_file_name), "deformed_%s", argv[1]);
    FILE* out_file = fopen(out_file_name, "w");
    if (out_file == NULL) {
        printf("Error creating file %s\n", out_file_name);
        fclose(in_file);
        return 1;
    }

    // Read the input file line by line
    char line[10000];
    while (fgets(line, sizeof(line), in_file) != NULL) {
        // Remove leading whitespaces
        int i = 0;
        while (line[i] == ' ' || line[i] == '\t') {
            i++;
        }

        // Write the line to the output file
        fputs(line + i, out_file);
    }

    // Close the files
    fclose(in_file);
    fclose(out_file);

    return 0;
}
