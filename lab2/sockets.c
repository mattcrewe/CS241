#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main (int argc, char** argv) {
  int conn_s = socket(AF_INET, SOCK_STREAM, 0);

  struct addrinfo hints;
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = 0;
  hints.ai_flags = AI_PASSIVE;

  struct addrinfo *addr;
  getaddrinfo("www.kylegough.co.uk", "80", &hints, &addr);

  connect(conn_s, addr->ai_addr, sizeof(struct sockaddr_in));

  char *http_request = "GET / HTTP/1.1\r\nConnection: close\r\n\r\n";

  write(conn_s, http_request, strlen(http_request));

  char buffer[2048];

  read(conn_s, buffer, sizeof(char) * 2048);

  FILE* output = fopen("output.txt", "w");
  fwrite(buffer, sizeof(char), 2048, output);
  fclose(output);

  printf("%s", buffer);
  close(conn_s);
  freeaddrinfo(addr);

  return 0;
}
