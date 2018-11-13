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
  job_t *j = NULL;

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
        d_linked_list_t *temp_list = init_d_linked_list();
        while (jobs->size != 0){
          // first job
          if ( j == NULL){
            j = dequeue(jobs);
            enqueue(temp_list, j); 
          }
          else {
            job_t *temp = dequeue(jobs);
            enqueue(temp_list, temp);

            if(temp->required_time < j->required_time){
              j = temp;
            }
          }
        }
        jobs = temp_list;

        break;
      }
    case RR:
      {
        //TODO
        break;
      }
    default:
      perror("invalid MODE");
      return NULL;
  }


  return j;
}


