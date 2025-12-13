#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char** argv)
{
    FILE *inputFile = fopen("./input.txt", "r");
    FILE *outputFile = fopen("./output.txt", "w");
    if (inputFile == NULL || outputFile == NULL) {
        printf("oopsies\n");
        return -1;
    }
    printf("meow\n");

    char line[5];
    int dial = 50, sum = 0;
    while (fgets(line, 6, inputFile) != NULL)
    {
        char dir = line[0];
        int move = atoi(&line[1]);
        if (dir == 'L') 
            dial = (dial - move) % 100;
        else 
            dial = (dial + move) % 100;
        if (dial == 0) sum++;
    }
    printf("sum: %d\n", sum);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
