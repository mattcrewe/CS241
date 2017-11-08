#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static pthread_mutex_t muxlock = PTHREAD_MUTEX_INITIALIZER;

void *thread_code (void *arg) {
  pthread_mutex_lock(&muxlock);
  printf("Adding 10000!\n");
  int *ptr = (int *) arg;
  int i = 0;
  for (i = 0; i < 10000; i++)
    *ptr = *ptr + 1;
  pthread_mutex_unlock(&muxlock);
  pthread_exit(NULL);
}

int main () {
  pthread_t threads[10];
  int total = 0;
  int i;

  for (i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, &thread_code, &total);
  }

  for (i = 0; i < 10; i++) {
    pthread_join(threads[i], (void *) NULL);
  }

  printf("\nTotal: %d\n", total);

  exit(EXIT_SUCCESS);
}
