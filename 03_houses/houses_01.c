#include <stdlib.h>

#include "position.h"

int main(void) {
  FILE *fp = fopen("input.txt", "r");
  if (fp == NULL) {
    perror("error opening file");
    return EXIT_FAILURE;
  }
  struct pos cur_pos = {MAX_CHARS, MAX_CHARS};
  bool *seen = NULL;
  int answer = establish_map(&seen, cur_pos, fp);
  int c;
  while ((c = fgetc(fp)) != EOF) {
    char_to_pos(c, &cur_pos);
    answer += count_spot(cur_pos, seen);
  }
  free(seen);
  fclose(fp);
  printf("answer is %d\n", answer);
  return 0;
}
