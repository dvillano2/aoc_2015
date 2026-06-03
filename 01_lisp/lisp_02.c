#include <stdio.h>

int main(void) {
  FILE *fp = fopen("input.txt", "r");
  int current_floor = 0;
  int counter = 0;
  int c;
  while ((c = fgetc(fp)) != EOF) {
    counter++;
    if (c == '(') {
      current_floor++;
    } else if (c == ')') {
      current_floor--;
    }
    if (current_floor == -1) {
      break;
    }
  }
  fclose(fp);
  printf("answer is %d\n", counter);
  return 0;
}
