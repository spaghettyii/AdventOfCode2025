#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char** argv)
{
    FILE *inputFile = fopen("./input.txt", "r");
    FILE *outputFile = fopen("./output.txt", "w");
    if (inputFile == NULL || outputFile == NULL) {
        printf("oopsies\n");
        fclose(outputFile);
        fclose(inputFile);
        return -1;
    }

    char line[6];
    int dial = 1000050, sum = 0, temp;
    while (fgets(line, 6, inputFile) != NULL)
    {
        char dir = line[0];
        int move = atoi(&line[1]);
        if (dir == 'L') {
            temp = (dial - move);
        } else {
            temp = (dial + move);
        }
        int tempDiff = temp / 100;
        int dialDiff = dial / 100;
        sum += (tempDiff > dialDiff ? tempDiff - dialDiff : dialDiff - tempDiff);
        if (dir == 'L' && temp % 100 == 0) { sum++; }
        if (dir == 'L' && dial % 100 == 0) { sum--; }
        dial = temp;
        fprintf(outputFile, "dial: %d, sum: %d\n", dial, sum);
    }

    fclose(outputFile);
    fclose(inputFile);

    return 0;
}
