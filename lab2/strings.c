#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, int **argv) {
  char* string_a = "my name is ";
  char* string_b = "jeff";
  char* string_c = " i want to die";

  char *tmp_string = (char *) calloc(strlen(string_a) + strlen(string_b) + strlen(string_c) + 1, sizeof(char));

  strcat(tmp_string, string_a);
  strcat(tmp_string, string_b);
  strcat(tmp_string, string_c);
  printf("%s\n", tmp_string);
  return 0;
}
