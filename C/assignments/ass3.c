#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdbool.h>

//mutex lock
pthread_mutex_t lock;

//global variables for threads
int acc1 = 0;
int acc2 = 0;
//if depositers have added money to account
bool dep1 = false;
bool dep2 = false;
//method declarations
void *deposit(char *account, int amount);
void *withdraw(char *account, int amount); 
void *transfer(char *account1, char *account2, int amount);
//for adding arguments from command line
int main(int argc, char *argv[]) {
    //opens the file that is passed as an argument from the command line
    FILE *f = fopen(argv[1], "r");
    //max length of each line
    char line[256];
    //token pointer
    char *token;
    //array to store tokens
    char *array[20];
    //declare the threads
    pthread_t deposit_t, withdraw_t, transfer_t;

    //if mutex lock failed throw an init error
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }

    //parses line by line the input file
    while (fgets(line, sizeof(line), f)) {
        //counts how many tokens are in the array
        int i = 0;
        //get first token in line
        token = strtok(line, " ");
        //tokenize string and add tokens to an array
        while (token != NULL) {
            array[i++] = token;
            token = strtok(NULL, " ");
        }
        //checks each token and performs a function depending on what the token is
        for(int j = 0; j < i; j++) {
            if(strcmp(array[j], "dep1")){
                dep1 = true; 
            }
            else if(strcmp(array[j], "dep2")) {
                dep2 = true;
            }

            else if(strcmp(array[j], "d")) {
                pthread_create(&deposit_t, NULL, deposit(array[++j], atoi(array[++j])), NULL);
            }

            else if(strcmp(array[j], "w")) {
                pthread_create(&withdraw_t, NULL, withdraw(array[++j], atoi(array[++j])), NULL);
            }

            else if (strcmp(array[j], "t")) {
                pthread_create(&transfer_t, NULL, transfer(array[++j], array[++j], atoi(array[++j])), NULL);
            }
        }
    }
    //close the file
    fclose(f);


    //join all the threads together
    pthread_join(deposit_t, NULL);
    pthread_join(withdraw_t, NULL);
    pthread_join(transfer_t, NULL);
    return 0;
}
//adds money into an account
void *deposit(char *account, int amount) {
    //locks because critical function
    pthread_mutex_lock(&lock);
    if (strcmp(account, "acc1")) {
        acc1 += amount;
    }
    else {
        acc2 += amount;
    }
    //unlocks
    pthread_mutex_unlock(&lock);
}
//withdraw money from an account
void *withdraw(char *account, int amount) {
    pthread_mutex_lock(&lock);
    if (strcmp(account, "acc1")) {
        acc1 -= amount;
    }

    else {
        acc2 -= amount;
    }
    pthread_mutex_unlock(&lock);
}
//transfer money from one account to another
void *transfer(char* account1, char* account2, int amount) {
    pthread_mutex_lock(&lock);
    if (strcmp(account1, "acc1")) {
        withdraw("acc1", amount);
        deposit("acc2", amount);
    }

    else {
        withdraw("acc2", amount);
        deposit("acc1", amount);
    }

    pthread_mutex_unlock(&lock);
}


