#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITR 10000000

void process_array()
{
    FILE *file;
    file = fopen("input.txt", "r");
    int *input = calloc(sizeof(int), NUM_ITR);

    int i = 0;
    int in;
    int out = 0;

    while(fscanf(file, "%d", &in) == 1) {
        input[i] = in;
        i++;
    }

    if(input) free(input);
    fclose(file);
}

int main() {
    double t;
    clock_t start, end;

    start = clock();
    process_array();
    end = clock();

    t = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;

    printf("Process took %f milliseconds\n", t);
    
    return 0;
}
