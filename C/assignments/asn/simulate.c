/******************************************************************************
 *
 ******************************************************************************/

#include "simulate.h"

int memory, max_memory;
FILE *fp;
linked_stack_t *jobs;
char *allocate = "Allocating";
char *deallocate = "Deallocating";

void simulate(int memory_value, linked_stack_t *stack)
{
  int i;
  max_memory = memory_value;
  fp = fopen(SYSTEM_OUTPUT, "ab+");
  pthread_t thread[NUMBER_OF_THREADS];

  while(jobs->size != 0){
    for(i = 0; i < NUMBER_OF_THREADS; i++){
      pthread_create(&thread[i], NULL, do_work,  (job_t*)pop(stack));

    }

    for(i = 0; i < NUMBER_OF_THREADS; i++){
      pthread_join(thread[i], NULL);
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
  if((((job_t*)input)->required_memory + memory) > max_memory) {
    print_insufficient_memory(fp, ((job_t*)input)->required_memory);
    push(jobs, (job_t*)input);
  }

  // enough memory available
  else{

    while(((job_t*)input)->required_time > 0){
      print_starting(fp, ((job_t*)input)->number);
      print(fp, allocate, ((job_t*)input)->required_memory);
      memory += ((job_t*)input)->required_memory;
      ((job_t*)input)->required_time -= 2;
      sleep(2);

    }
    print_completed(fp, ((job_t*)input)->number);
    print(fp, deallocate, ((job_t*)input)->required_memory);
    memory -= ((job_t*)input)->required_memory;
  }
}

