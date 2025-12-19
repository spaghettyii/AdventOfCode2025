#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


void part2 (FILE *inputFp)
{
    unsigned long sum = 0;
    char *line = malloc(sizeof(char) * 100);
    while ((line = fgets(line, INT_MAX, inputFp)) != NULL)
    {
        int len = strlen(line) - 1;
        int maxDigits[12] = {0};
        int maxIndices[12] = {0};
        maxIndices[0] = -1;
        for (int i = 0; i < 12; i++)
        {
            for (int j = maxIndices[i] + 1; j < len - (11 - i); j++)
            {
                if (line[j] - '0' > maxDigits[i]) {
                    maxDigits[i] = line[j] - '0';
                    if (i < 11) maxIndices[i + 1] = j;
                }
            }
        }
        unsigned long pow10 = 1;
        unsigned long temp = 0;
        for (int i = 11; i >= 0; i--)
        {
            temp += pow10 * maxDigits[i];
            pow10 *= 10;
        }
        // printf("curr: %lu\n", temp);
        sum += temp;
    }
    printf("sum: %lu\n", sum);
    return;
}

void part1(FILE* inputFile)
{
    char *line = malloc(sizeof(char) * 100);
    int sum = 0;
    while ((line = fgets(line, INT_MAX, inputFile)) != NULL)
    {
        int len = strlen(line);
        int maxDigit1 = 0;
        int maxIndex = 0;
        for (int i = 0; i < len - 2; i++)
        {
            if (line[i] - '0' > maxDigit1) {
                maxDigit1 = line[i] - '0';
                maxIndex = i;
                if (line[i] == '9') break;
            }
        }

        int maxDigit2 = 0;
        for (int j = maxIndex + 1; j < len - 1; j++)
            if (line[j] - '0' > maxDigit2) maxDigit2 = line[j] - '0';
        int curr = maxDigit1 * 10 + maxDigit2;
        printf("curr: %d\n", curr);
        sum += curr; 
    }
    printf("sum: %d\n", sum);

    return;
}

int main (int argc, char **argv)
{
    FILE *inputFile = fopen("./input.txt", "r");
    if (inputFile == NULL) { 
        printf("oopsies\n");
        return -1;
    }

    //part1(inputFile);
    part2(inputFile);

    fclose(inputFile);

    return 0;
}
