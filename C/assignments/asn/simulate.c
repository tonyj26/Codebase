/**********************************************************aaaaaaaasa********************
 *
 ******************************************************************************/

#include "simulate.h"

int memory, max_memory;
FILE *fp;
linked_stack_t *jobs;
char *allocate = "Allocating %d\n";
char *deallocate = "Deallocating %d\n";

void simulate(int memory_value, linked_stack_t *stack)
{
  int i;
  int k;
  jobs = stack;
  max_memory = memory_value;
  memory = max_memory;
  fp = fopen(SYSTEM_OUTPUT, "w");
  pthread_t thread[NUMBER_OF_THREADS];

  while(jobs->size != 0){
    for(i = 0; i < NUMBER_OF_THREADS; i++){

      if (jobs->head != NULL){
        pthread_create(&thread[i], NULL, do_work, pop(jobs));
      }  
      else{
        break;
      }
    }

    for( k = 0; k < i; k++){
      pthread_join(thread[k], NULL);
    }
  }

  fclose(fp);
}

void *do_work(void *input)
{

  // memory exceeed, drop job
  if(memory > max_memory){
    print_exceed_memory(fp, ((job_t*)input)->number);
  }

  //insufficient memory, push onto stack
  if((((job_t*)input)->required_memory) > memory) {
    print_insufficient_memory(fp, ((job_t*)input)->number);
    push(jobs, input);
  }

  // enough memory available
  else{

    print_starting(fp, ((job_t*)input)->number);
    print(fp, allocate, ((job_t*)input)->required_memory);
    sleep(((job_t*)input)->required_time);
    memory -= ((job_t*)input)->required_memory;
    ((job_t*)input)->required_time -= ((job_t*)input)->required_time;

    print_completed(fp, ((job_t*)input)->number);
    print(fp, deallocate, ((job_t*)input)->required_memory);
    memory += ((job_t*)input)->required_memory;
  }
}

