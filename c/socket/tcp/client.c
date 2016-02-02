/*

   Client:
      => Create a socket with the socket()
      => Connect the socket to the address of the server using the connect() 
         system call.
      => Send and receive data, use the read() and write() system calls

*/
#include
#include
#include
#include
#include  

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    if (argc &lt; 3)
    {
       fprintf(stderr,&quot;usage %s hostname port\n&quot;, argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd h_addr,(char *)&amp;serv_addr.sin_addr.s_addr,server-&gt;h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,&amp;serv_addr,sizeof(serv_addr)) &lt; 0)
    {
          error(&quot;ERROR connecting&quot;);
    }
    printf(&quot;Please enter the message: &quot;);
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    n = write(sockfd,buffer,strlen(buffer));
    if (n &lt; 0)
    {
           error(&quot;ERROR writing to socket&quot;);
    }
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n &lt; 0)
    {
           error(&quot;ERROR reading from socket&quot;);
    }
    printf(&quot;%s\n&quot;,buffer);
    return 0;
}

