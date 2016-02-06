#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

//int i=0;
void doSomeWork(char* name) {
   const int NUM_TIMES = 2;
   //for (; i<NUM_TIMES; i++) {
   for (int i=0; i<NUM_TIMES; i++) {
      sleep(rand() % 4);
      printf("Done pass %d for %s\n", i, name);
   }
}

int main(int argc, char *argv[])
{
   printf("I am: %d\n", (int)getpid());

   sleep(5);

   pid_t pid = fork();
   srand((int)pid);
   printf("fork returned: %d\n", (int) pid);

   if (pid < 0)
      printf("Error: fork() failed!\n");
   else if (pid == 0) {
      printf("I am the child with pid %d\n", (int)getpid());
      doSomeWork("Child");
//      sleep(5);
//      printf("Child exiting ...\n");
      exit(42); // child is returning 42 to parent
   }

   // Must be the parent
   printf("I am the parent, waiting for child to end.\n");
   sleep(10);
   //doSomeWork("Parent");

   int status = 0;
   pid_t childpid = wait(&status); // wait until the child to end first.
   printf("Parent knows child %d finished with status %d.\n", (int)childpid, status);
   int childReturnValue = WEXITSTATUS(status);
   printf("Return value = %d\n", childReturnValue);  // get 42 here!
   sleep(60);

//   printf("I am: %d\n", (int)getpid());

   return 0;
}
