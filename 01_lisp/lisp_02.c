#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fp = fopen("input.txt", "r");
  if (fp == NULL) {
    perror("error opening file");
    return EXIT_FAILURE;
  }
  int current_floor = 0;
  int counter = 0;
  int c;
  while ((c = fgetc(fp)) != EOF) {
    counter++;
    current_floor += c == ')';
    current_floor -= c == '(';
    if (current_floor == -1) {
      break;
    }
  }
  fclose(fp);
  printf("answer is %d\n", counter);
  return 0;
}
