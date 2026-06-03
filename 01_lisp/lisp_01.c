#include <stdio.h>

int main(void) {
  FILE *fp = fopen("input.txt", "r");
  int answer = 0;
  int c;
  while ((c = fgetc(fp)) != EOF) {
    if (c == '(') {
      answer++;
    } else if (c == ')') {
      answer--;
    }
  }
  fclose(fp);
  printf("answer is %d\n", answer);
  return 0;
}
