#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *thread_code (void *arg) {
  printf("threads LMFAO id: %d\n", pthread_getthreadid_np());
  pthread_exit(NULL);
}

int main () {

  pthread_t threads[10];
  int i;
  for (i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, &thread_code, (void *) NULL);
  }

  for (i = 0; i < 10; i++) {
    pthread_join(threads[i], (void *) NULL);
  }


  exit(EXIT_SUCCESS);
}
