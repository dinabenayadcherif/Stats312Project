//
//  trial8.c
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
    FILE *inputFile, *outputFile;
    inputFile = fopen("input.txt", "r");
    int *input = calloc(sizeof(int), NUM_ITR);
    outputFile = fopen("output_trial_8.txt", "w+");
    
    pid_t pid;
    pid = fork();
    
    if (pid == 0){
        char in[60];
        int i;
        i = 0;
        while(fgets(in, sizeof(in), inputFile)!=NULL && i < NUM_ITR/2) {
            input[i] = atoi(in);
            i++;
        }
        
        for(i =0; i < NUM_ITR/2; i++) {
            fprintf(outputFile, "%d\n", input[i]);
        }
        
    }
    
    else {
        char in[60];
        int i;
        i = NUM_ITR/2;
        while(fgets(in, sizeof(in), inputFile)!=NULL && i < NUM_ITR) {
            input[i] = atoi(in);
            i++;
        }
        for(i =NUM_ITR/2; i < NUM_ITR; i++) {
            fprintf(outputFile, "%d\n", input[i]);
        }
    }
    
    if(input) free(input);
    fclose(inputFile);
    fclose(outputFile);
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
