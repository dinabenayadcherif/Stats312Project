#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITR 10000000

void process_array()
{
  // Initialize file to write to
  FILE *fp;
  fp = fopen("output_trial_3.txt", "w+");
  // Initialize array
  int *output = calloc(sizeof(int), NUM_ITR);
  // Input will be 0-10 sequentially
  int i = 0;
  int in = 0;
  int out = 0;
  for(i = 0; i < NUM_ITR; i++)
    {
      in = i % 10;
      out = in * 3;
      output[i] = out;
      fprintf(fp, "%d\n", output[i]);
    }
  if(output) free(output);
  fclose(fp);
}

int main(int argc, char *argv[])
{
  double t;
  clock_t start, end;

  start = clock();
  process_array();
  end = clock();

  t = (double) (end - start) / CLOCKS_PER_SEC * 1000.0;

  printf("Process took %f milliseconds\n", t);

  return 0;
}

