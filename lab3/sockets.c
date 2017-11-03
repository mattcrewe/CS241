#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

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

  fcntl(sockfd, F_SETFL, O_NONBLOCK);

  while (1) {
    if (should_exit) {
      exit(EXIT_SUCCESS);
    }

    if ((conn_s = accept(sockfd, NULL, NULL)) < 0) {
      if ((errno == EAGAIN) || (errno == EWOULDBLOCK))
        continue;
      perror("error kek lmao \n");
      exit(EXIT_FAILURE);
    }

    long conn_s_flags = fcntl(conn_s, F_GETFL);
    fcntl(conn_s, F_SETFL, conn_s_flags & ~O_NONBLOCK);


    char buffer[2048];

    read(conn_s, buffer, sizeof(char) * 2048);
    printf("%s", buffer);

    close(conn_s);
  }

  close (sockfd);

  return 0;
}
