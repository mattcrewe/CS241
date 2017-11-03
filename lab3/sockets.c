#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char** argv) {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(42069);
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

  int res = bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
  if (res < 0) {
    printf("error lol");
    return 1;
  }

  res = listen(sockfd, 69);
  if (res < 0) {
    printf("error lol");
    return 1;
  }

  int conn_s;
  int should_exit = 0;

  while (1) {
    if ((conn_s = accept(sockfd, NULL, NULL)) < 0) {
      perror("error kek lmao \n");
      return 1;
    }


    char buffer[2048];

    while (!should_exit) {
      read(conn_s, buffer, sizeof(char) * 2048);
      if (strncmp(buffer, "memes", strlen("memes"))) {
        should_exit = 1;
      }
      printf("%s", buffer);
    }

    close(conn_s);
  }

  close (sockfd);

  return 0;
}
