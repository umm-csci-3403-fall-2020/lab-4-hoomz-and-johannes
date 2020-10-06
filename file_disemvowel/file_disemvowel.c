#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 1024

bool is_vowel(char c){
    /*
     * Returns true if c is a vowel (upper or lower case), and
     * false otherwise.
     */
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }

int copy_non_vowels(int num_chars, char *in_buf, char *out_buf){

    int x = 0;

    for (int i = 0; i < num_chars; i++)
    {
        if (is_vowel(in_buf[i]) == false)
        {
            out_buf[x] = in_buf[i];
            x++;
        }
    }
    return x;
}

void disemvowel(FILE *inputFile, FILE *outputFile){
    /*
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out.
     */
    char* buff_start;
    char * buff_end;
    buff_start = (char *)calloc(BUF_SIZE, sizeof(char));
    buff_end = (char *)calloc(BUF_SIZE, sizeof(char));
    while (feof(inputFile) == false){
        size_t number = fread(buff_start, 1, BUF_SIZE, inputFile);
        int x = copy_non_vowels(number, buff_start, buff_end);
        fwrite(buff_end, 1, x, outputFile);
    }
    free(buff_start);
    free(buff_end);
    fclose(inputFile);
}

int main(int argc, char *argv[]){
    // You should set these to `stdin` and `stdout` by default
    // and then set them to user specified files when the user
    // provides files names as command line arguments.
    FILE *inputFile;
    FILE *outputFile;

    if (argc == 1){
        inputFile = stdin;
        outputFile = stdout;
    }
    else if (argc == 2){
        inputFile = fopen(argv[1], "r");
        outputFile = stdout;
    }
    else if (argc == 3){
        inputFile = fopen(argv[1], "r");
        outputFile = fopen(argv[2], "w+");
        fclose(outputFile);
    }
    // Code that processes the command line arguments
    // and sets up inputFile and outputFile.
    disemvowel(inputFile, outputFile);
    return 0;
}