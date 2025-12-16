#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv)
{
    char buffer[] = "100-100,1000-1000";
    char *new = strtok(buffer, ",");
    printf("first call: %s, and length: %lu\n", new, strlen(new));
    char *next = strtok(NULL, ",");
    printf("second call: %s, and length: %lu\n", next, strlen(next));
    printf("is third call null: %d\n", (strtok(NULL, ",") == NULL));
    printf("atoi buffer: %d\n", atoi(buffer));
    printf("atoi buffer[3]: %d\n", atoi(&buffer[3]));
    printf("atoi buffer[4]: %d\n", atoi(&buffer[4]));
    int len = strlen(buffer);
    int dashindex;
    for (int i = 0; i < len; i++)
        if (new[i] == '-') dashindex = i;
    printf("dashindex: %d\n", dashindex);
    return 0;
}
