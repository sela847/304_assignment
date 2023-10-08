/* do not add other includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

double getTime(){
  struct timeval t;
  double sec, msec;
  
  while (gettimeofday(&t, NULL) != 0);
  sec = t.tv_sec;
  msec = t.tv_usec;
  
  sec = sec + msec/1000000.0;
  
  return sec;
}
 
/* for task 1 only */
void usage(void)
{
	fprintf(stderr, "Usage: cachetest1/2 [--repetitions M] [--array_size N]\n");
	exit(1);
}

int main (int argc, char *argv[])
{
  double t1, t2; 
  
  /* variables for task 1 */

  // L1: 32KB  L2:256KB   L3: 2 or 3 -> 8MB
  unsigned int L1Max = 8192; // (32KB / 4Bytes (integer)) = 8192
  unsigned int L3Max = 4194304; // (2 * 8MB  / 4 Bytes)
  unsigned int M = 1000;
  //unsigned int N = 256*1024; 
  unsigned int N = L3Max;
  unsigned int i;
  unsigned int sum = 0;
	
  /* declare variables; examples, adjust for task */
	int *a;

	//double  a[100];
 
  
  /* parameter parsing task 1 */
  for(i=1; i<(unsigned)argc; i++) {
	  if (strcmp(argv[i], "--repetitions") == 0) {
		  i++;
		  if (i < argc)
			  sscanf(argv[i], "%u", &M);
		  else
			  usage();
	  } else if (strcmp(argv[i], "--array_size") == 0) {
		  i++;
		  if (i < argc)
			  sscanf(argv[i], "%u", &N);
		  else
			  usage();
	  } else usage();
  }

    
  /* allocate memory for arrays; examples, adjust for task */
	 a = malloc (N * sizeof(int));

	 /* initialise arrray elements */
  for (i = 0; i < N; i++) {
    a[i] = 0; 
  }
	 
  t1 = getTime();
  /* code to be measured goes here */
  /***************************************/
  for (unsigned int j = 0; j<M;j++) { // M iterations
    for (i=0; i<N; i++) { // N iterations
      sum += a[i];
    }
  }
  /***************************************/
	t2 = getTime(); 
  
  /* output; examples, adjust for task */
  printf("M: %d, N: %d\n",M,N);
  printf("time: %6.2f secs\n",(t2 - t1));
  printf("Sum: %d\n",sum);
  printf("Time per iteration in ns: %f\n",((double) (t2-t1)/((double) M*(double) N)) * 1000000000);

  /* IMPORTANT: also print the result of the code, e.g. the sum, 
   * otherwise compiler might optimise away the code */
  
  /* free memory; examples, adjust for task */
  //free(a);

  return 0;  
}
