//
//  trial6.c
//  
//
//  Created by Dina Benayad-Cherif on 11/27/16.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

#define NUM_ITR 10000000

void process_array()
{
    FILE *file;
    file = fopen("input.txt", "r");
    int *input = calloc(sizeof(int), NUM_ITR);
    
    pid_t pid;
    pid = fork();
    
    if (pid == 0){
        char in[60];
        int i;
        i = 0;
        while(fgets(in, sizeof(in), file)!=NULL && i < NUM_ITR/2) {
            input[i] = atoi(in);
            i++;
        }
    }
    
    else {
        char in[60];
        int i;
        i = NUM_ITR/2;
        while(fgets(in, sizeof(in), file)!=NULL && i < NUM_ITR) {
            input[i] = atoi(in);
            i++;
        }
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
