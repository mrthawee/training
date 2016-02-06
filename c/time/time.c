#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]) {
   time_t ltime;     /* calendar time */
   ltime = time(NULL);  /* get current cal time */
   printf("%s", asctime(localtime(&ltime)));
}
