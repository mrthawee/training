#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_LOOPS 500000000
long long sum = 0;

//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t sem;

//void counting_function(int offset) {
void* counting_function(void *arg) {
   int offset = *(int *)arg;
   for (int i=0; i<NUM_LOOPS; i++) {
      // Start critical section
      //pthread_mutex_lock(&mutex);
      sem_wait(&sem);

      sum += offset;

      //pthread_mutex_unlock(&mutex);
      sem_post(&sem);
      // End critical section
   }

   pthread_exit(NULL);
}

int main(void) {
   //counting_function(1);
   //counting_function(-1);

   sem_init(&sem, 0, 1); // 0 = shared between threads 1 = binary semaphore
 
   // Spawn threads
   pthread_t id1;
   int offset1 = 1;
   pthread_create(&id1, NULL, counting_function, &offset1);

   pthread_t id2;
   int offset2 = -1;
   pthread_create(&id2, NULL, counting_function, &offset2);

   // Wait for threads to finish
   pthread_join(id1, NULL);
   pthread_join(id2, NULL);


   printf("Sum = %lld\n", sum);
   return 0;
}
