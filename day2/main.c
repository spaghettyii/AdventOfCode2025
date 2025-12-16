#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

int power (int a, int r)
{
    if (r == 0) return 1;
    if (r == 1) return a;
    return power(a, r - 1) * a;
}

int digitNum (uint64_t a)
{
    if (a < 10) return 1;
    return digitNum(a / 10) + 1;
}

bool isInvalidID(uint64_t a)
{
    int digits = digitNum(a);
    for (int i = 1; i <= digits / 2; i++)
    {
        if (digits % i == 0) // divisible digits 
        {
            int divides = digits / i;
            uint64_t pow10 = power(10, i);
            uint64_t now = a % pow10;
            bool isRepeating = true;
            for (int j = 1; j < divides; j++)
                if (now != (a / power(pow10, j)) % pow10)
                    isRepeating = false; 
            if (isRepeating) return true;
        }
    }
    return false;
}

uint64_t findInvalidIDSum(uint64_t lo, uint64_t hi)
{
    printf("-------------------------- (%llu, %llu) --------------------------\n", lo, hi);
    uint64_t sum = 0;
    for (uint64_t i = lo; i <= hi; i++)
        if (isInvalidID(i)) 
        { 
            printf("invalid ID %llu\n", i);
            sum+=i; 
        }
    printf("sum: %llu in range (%llu, %llu)\n", sum, lo, hi);
    return sum;
}

int main (int argc, char **argv)
{
    FILE* inputFile = fopen("./input.txt", "r");
    if (inputFile == NULL) {
        printf("no files :(\n");
        return -1;
    }

    uint64_t sum = 0;
    char *fileLine = malloc(sizeof(char) * INT_MAX); 
    fileLine = fgets(fileLine, INT_MAX, inputFile);
    if (fileLine == NULL) {
        printf("oopsies\n");
        return -1;
    }
    char *rangeString = strtok(fileLine, ",");
    do {
        // Getting ranges
        int len = strlen(rangeString);
        int dashindex;
        for (int i = 0; i < len; i++)
            if (rangeString[i] == '-') dashindex = i;
        uint64_t low = atoll(rangeString);
        uint64_t high = atoll(&rangeString[dashindex + 1]);

        // range: (low, high)
        // Finding invalid IDs
        sum += findInvalidIDSum(low, high);
    } while ((rangeString = strtok(NULL, ",")) != NULL);

    printf("sum: %llu\n", sum);
    
    free(fileLine);
    fclose(inputFile);

    return 0;
}
