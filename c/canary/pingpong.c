#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t mutex;
pthread_cond_t  condc, condp;
int flag = 0;
int data = 0;

#define MAX 10

void *ping(void *ptr) {
   int i;
   for (i=0; i<MAX; i++) {
      pthread_mutex_lock(&mutex);
      while (flag != 0)
         pthread_cond_wait(&condp, &mutex);
      flag = i+1; // set to non-zero
      data = rand();
      printf("ping %d : ", data);
      pthread_cond_signal(&condc);
      pthread_mutex_unlock(&mutex);
   }

   pthread_exit(0);
}

void *pong(void *ptr) {
   int i;
   for (i=0; i<MAX; i++) {
      pthread_mutex_lock(&mutex);
      while (flag == 0)
         pthread_cond_wait(&condc, &mutex);
      flag = 0; // set to zero
      printf(" pong got data = %d\n", data);
      pthread_cond_signal(&condp);
      pthread_mutex_unlock(&mutex);
   }
   pthread_exit(0);
}

int main(void) {

   srand(time(NULL));

   pthread_t tid1, tid2;

   pthread_mutex_init(&mutex, NULL);
   pthread_cond_init(&condc, NULL);
   pthread_cond_init(&condp, NULL);

   pthread_create(&tid1, NULL, ping, NULL);
   pthread_create(&tid2, NULL, pong, NULL);

   pthread_join(tid1, NULL);
   pthread_join(tid2, NULL);

   pthread_mutex_destroy(&mutex);
   pthread_cond_destroy(&condc);
   pthread_cond_destroy(&condp);
}
