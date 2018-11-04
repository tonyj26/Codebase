/**********************************************************aaaaaaaasa********************
 *
 ******************************************************************************/

#include "simulate.h"

int memory, max_memory;
FILE *fp;
linked_stack_t *jobs;

// additional print statements 
char *allocate = "Allocating %d\n";
char *deallocate = "Deallocating %d\n";
char *memat = "Memory at %d\n";
char *running = "Running job #%d\n";

void simulate(int memory_value, linked_stack_t *stack)
{
  int i, k;
  jobs = stack;
  max_memory = memory_value;
  memory = max_memory;
  fp = fopen(SYSTEM_OUTPUT, "w");
  pthread_t thread[NUMBER_OF_THREADS];

  while(jobs->size != 0){
    for(i = 0; i < NUMBER_OF_THREADS; i++){

      if (jobs->head != NULL){
        if(pthread_create(&thread[i], NULL, do_work, pop(jobs)) != 0){
          perror("Thread Error");
        }
      }  
      else{
        break;
      }
    }

    // join all the threads
    for( k = 0; k < i; k++){
      pthread_join(thread[k], NULL);
    }
  }

  // close open file
  fclose(fp);
}

// thread function 
void *do_work(void *input)
{

  //cast at the start to dereference
  job_t job = *(job_t*)input;

  // memory exceeed, drop job
  if(job.required_memory > max_memory){
    print_exceed_memory(fp, job.number);
  }

  //insufficient memory, push onto stack
  else if(job.required_memory > memory) {
    print_insufficient_memory(fp, job.number);
    push(jobs, input);
  }

  // enough memory available
  else{

    print_starting(fp, job.number);
    memory -= job.required_memory;
    print(fp, allocate, job.required_memory);
    sleep(2);
    job.required_time -= 2;

    print(fp, memat, memory);

    // simulate scheduling
    while (job.required_time > 0){
      print(fp, running, job.number);
      sleep(2);
      job.required_time -= 2;
    }

    print_completed(fp, job.number);
    memory += job.required_memory;
    print(fp, deallocate, job.required_memory);

    print(fp ,memat, memory);
  }
}

