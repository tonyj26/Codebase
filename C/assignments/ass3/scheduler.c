/******************************************************************************
 *
 * Name: 	Zaid Albirawi
 * Email: 	zalbiraw@uwo.ca
 *
 * scheduler.c
 *
 ******************************************************************************/

#include "scheduler.h"

/*
 * FCFS = 0
 * LIFO = 1
 * SJF = 2
 * RR = 3
 */

job_t *get_next_job(int mode, d_linked_list_t* jobs) {
  job_t *j;
  int stack_length, i;

  switch (mode){
    case FCFS:
      {
        j = dequeue(jobs);
        break;
      }

    case LIFO:
      {
        j = pop(jobs);
        break;
      }
    case SJF:
      {
        // sort list into shortest job first
        // temp list

        job_t *temp;
        j = dequeue(jobs);
        stack_length = jobs->size;


        for (i = 0; i < stack_length; i++){
          temp = dequeue(jobs);
          if (temp->required_time < j->required_time){
            enqueue(jobs, j);
            j = temp;
          }
          else {
            enqueue(jobs, temp);
          }
        }

  /*

        d_linked_list_t *temp_list = init_d_linked_list();
        while (jobs->size != 0){
          // first job
          if ( j == NULL){
            j = dequeue(jobs);
            enqueue(temp_list, j);
          }
          if (jobs->size != 0) {
            job_t *temp = dequeue(jobs);
            enqueue(temp_list, temp);

            if(temp->required_time < j->required_time){
              j = temp;
            }
          }
        }
        jobs = temp_list;

        */
        break;
      }
    case RR:
      {
        //TODO
        j = dequeue(jobs);
        break;
      }
    default:
      perror("invalid MODE");
      return NULL;
  }


  return j;
}
