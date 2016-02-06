// compile and run this one several times.
// issue: "Hello there!" may or may not be printed
#include <stdio.h>
#include <pthread.h>

void myfunc1(void *ptr);
void myfunc2(void *ptr);

char buf[24];

int main(int argc, char *argv[]) {
   pthread_t thread1;
   pthread_t thread2;

   char *msg1 = "Thread 1";
   char *msg2 = "Thread 2";

   pthread_create(&thread1, NULL, (void*)&myfunc1, (void*)msg1);
   pthread_create(&thread2, NULL, (void*)&myfunc2, (void*)msg2);

   pthread_join(thread1, NULL);
   pthread_join(thread2, NULL);

   return 0;
}

void myfunc1(void *ptr) {
   char *msg = (char *)ptr;

   printf("%s\n", msg);

   sprintf(buf, "%s", "Hello there!");

   pthread_exit(0);
}

void myfunc2(void *ptr) {
   char *msg = (char *)ptr;

   printf("%s\n", msg);

   printf("%s\n", buf);

   pthread_exit(0);
}
