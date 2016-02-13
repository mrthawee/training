/*
 *  Solution to Producer Consumer Problem
 *  Using Ptheads, a mutex and condition variables
 *  From Tanenbaum, Modern Operating Systems, 3rd Ed.
 */


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

#define INTERVAL  50  // number of milliseconds between read samples

#define MAX 10    /* Numbers to produce */
pthread_mutex_t the_mutex;
pthread_cond_t condc, condp;
int buffer = 0;

int hasDataRead = 0;

FILE *fp;

void readSample(void) {

  printf("Hi");

  /*
  struct timeval    tv;
  struct timezone   tz;
  struct tm        *tm;
  int               msec;
  char              ts[15];
  short             data;

  while (fscanf(fp,"%hd",&data) != EOF) {
    gettimeofday(&tv, &tz);
    tm = localtime(&tv.tv_sec);
    msec = tv.tv_usec/1000;
    sprintf(ts,"%d:%02d:%02d.%03d", tm->tm_hour, tm->tm_min, tm->tm_sec, msec);
    printf("Found %hd @ %s\n", data, ts);

    pthread_mutex_lock(&the_mutex);	// protect buffer
    while (hasDataRead != 0)
      pthread_cond_wait(&condp, &the_mutex);
    //enQ(data, ts);
    pthread_cond_signal(&condc);	// wake up consumer
    pthread_mutex_unlock(&the_mutex);	// release the buffer
  }

  //if (isEOF == EOF) {
  if (feof(fp) == EOF) {
    printf("Done.\n");
    fclose(fp);

    pthread_exit(0);
  }
  */
}

void readSampleTimer() {
  struct itimerval it_val;

  if (signal(SIGALRM, (void(*)(int))readSample) == SIG_ERR) {
    printf("Error: unable to catche SIGALRM\n");
    pthread_exit(0);
    //exit(-1);
  }
  printf("catch signal - ok\n");

  it_val.it_value.tv_sec = INTERVAL/1000;
  it_val.it_value.tv_usec = (INTERVAL*1000) % 1000000;
  it_val.it_interval = it_val.it_value;

  if (setitimer(ITIMER_REAL, &it_val, NULL) == -1) {
    printf("Error: calling setitimer() failed.\n");
    pthread_exit(0);
    //exit(-1);
  }
  printf("setitimer() - ok\n");

  while(1) {
    pause();
  }
}

void* producer(void *ptr) {
  /*
  int i;
  for (i = 1; i <= MAX; i++) {
    pthread_mutex_lock(&the_mutex);	// protect buffer
    while (buffer != 0)   // If there is something in the buffer then wait 
      pthread_cond_wait(&condp, &the_mutex);
    buffer = i;
    printf("P: buffer=%d\n",i);
    pthread_cond_signal(&condc);	// wake up consumer
    pthread_mutex_unlock(&the_mutex);	// release the buffer
  }
  pthread_exit(0);
  */

  fp = fopen("test.txt", "r");
  if (!fp) {
    printf("Error: can't open sample.bin\n");
    pthread_exit(0);
    //exit(-1);
  }
  printf("Open file - ok\n");

  readSampleTimer();
}

void* consumer(void *ptr) {
  int i;

  for (i = 1; i <= MAX; i++) {
    pthread_mutex_lock(&the_mutex);	// protect buffer
    while (buffer == 0)	// If there is nothing in the buffer then wait
      pthread_cond_wait(&condc, &the_mutex);
    buffer = 0;
    printf("C: buffer=%d\n",i);
    pthread_cond_signal(&condp);	// wake up consumer
    pthread_mutex_unlock(&the_mutex);	// release the buffer
  }
  pthread_exit(0);
}

int main(int argc, char **argv) {
  pthread_t pro, con;

  pthread_attr_t attr;
  pthread_attr_init(&attr);

  // Initialize the mutex and condition variables
  /* What's the NULL for ??? */
  pthread_mutex_init(&the_mutex, NULL);	
  pthread_cond_init(&condc, NULL); // Initialize consumer condition variable
  pthread_cond_init(&condp, NULL); // Initialize producer condition variable

  // Create the threads
//  pthread_create(&con, &attr, consumer, NULL);
  pthread_create(&pro, &attr, producer, NULL);

  // Wait for the threads to finish
  // Otherwise main might run to the end
  // and kill the entire process when it exits.
  //pthread_join(&con, NULL);
  //pthread_join(&pro, NULL);
//  pthread_join(con, NULL);
  pthread_join(pro, NULL);

  // Cleanup -- would happen automatically at end of program
  pthread_mutex_destroy(&the_mutex);	/* Free up the_mutex */
  pthread_cond_destroy(&condc);		/* Free up consumer condition variable */
  pthread_cond_destroy(&condp);		/* Free up producer condition variable */

  printf("-----\n");

}
