#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fp = fopen("input.txt", "r");
  if (fp == NULL) {
    perror("error opening the file");
    return EXIT_FAILURE;
  }
  int answer = 0;
  int c;
  while ((c = fgetc(fp)) != EOF) {
    answer += c == '(';
    answer -= c == ')';
  }
  fclose(fp);
  printf("answer is %d\n", answer);
  return 0;
}
