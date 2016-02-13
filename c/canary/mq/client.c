#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mqueue.h>

#include "common.h"

#include <time.h>
#include <unistd.h>
#include <sys/time.h>


int main(int argc, char **argv)
{
    mqd_t mq;
    //char buffer[MAX_SIZE];
    NodeType  buffer;

    /* open the mail queue */
    mq = mq_open(QUEUE_NAME, O_WRONLY);
    CHECK((mqd_t)-1 != mq);

    FILE *fp = fopen("test.txt", "r");
    if (!fp) {
      printf("Error: can't open file\n");
      exit(-1);
    }

   short  data;
   struct timeval tv;
   struct timezone tz;
   struct tm      *tm;
    while (fscanf(fp,"%hd",&data) != EOF) {
      gettimeofday(&tv, &tz);
      tm = localtime(&tv.tv_sec);
      int msec = tv.tv_usec/1000;
      char ts[15];
      sprintf(ts,"%d:%02d:%02d.%03d", tm->tm_hour, tm->tm_min,
                           tm->tm_sec, msec);
      strcpy(buffer.ts, ts);
      buffer.value = data;
      CHECK(0 <= mq_send(mq,(char*) &buffer, MAX_SIZE, 0));
      //CHECK(0 <= mq_send(mq,(char*) &buffer, sizeof(buffer), 0));
      usleep(50000);
    }

    // send end-of-msg to queue
    buffer.value = 0xFFFF;
    strcpy(buffer.ts,"EOF");
    CHECK(0 <= mq_send(mq, (char*)&buffer, MAX_SIZE, 0));
    //CHECK(0 <= mq_send(mq, (char*)&buffer, sizeof(buffer), 0));

/*
    printf("Send to server (enter \"exit\" to stop it):\n");

    do {
        printf("> ");
        fflush(stdout);

        memset(buffer, 0, MAX_SIZE);
        fgets(buffer, MAX_SIZE, stdin);

        // send the message 
        CHECK(0 <= mq_send(mq, &buffer, MAX_SIZE, 0));

    } while (strncmp(buffer, MSG_STOP, strlen(MSG_STOP)));
*/

    /* cleanup */
    CHECK((mqd_t)-1 != mq_close(mq));
    CHECK((mqd_t)-1 != mq_unlink(QUEUE_NAME));

    return 0;
}
