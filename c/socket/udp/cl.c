/*
Simple udp client

*/
#include<stdio.h>   //printf
#include<string.h> //memset
#include<stdlib.h> //exit(0);
#include<arpa/inet.h>
#include<sys/socket.h>
#include<ctype.h>

//#define SERVER "192.x.x.x"
#define SERVER "127.0.0.1"
#define BUFLEN 512  //Max length of buffer
#define PORT 8888   //The port on which to send data

void die(char *s)
{
perror(s);
exit(1);
}

int main(void)
{
struct sockaddr_in si_other;
int s, s2, i, slen=sizeof(si_other);
char buf[BUFLEN];
char message[BUFLEN];

if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)        // create a client socket
{
    die("socket");
}

memset((char *) &si_other, 0, sizeof(si_other));
si_other.sin_family = AF_INET;
si_other.sin_port = htons(PORT);

if (inet_aton(SERVER , &si_other.sin_addr) == 0)            // Create datagram with server IP and port.
{
    fprintf(stderr, "inet_aton() failed\n");
    exit(1);
}

while(1)
{
    printf("Enter message : ");
    gets(message);


    int a;
    char message2[BUFLEN];
    for(a=0;a<=BUFLEN-1;a++)
      {
        if(message[a] >= 97 && message[a] <= 122)
           message2[a] = toupper(message[a]);
        else
           message2[a] = tolower(message[a]);

      }


    if (sendto(s, message2, strlen(message2) , 0 , (struct sockaddr *) &si_other, slen)==-1)
    {
        die("sendto()");
    }


    //receive a reply and print it
    //clear the buffer by filling null, it might have previously received data
    memset(buf,'\0', BUFLEN);
    //try to receive some data, this is a blocking call
    if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen) == -1)        // read datagram from client socket
    {
        die("recvfrom()");
    }

    puts(buf);
}

close(s);
return 0;

}
