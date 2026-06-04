#include <stdlib.h>

#include "position.h"

struct pos *pick_pos(bool turn0, struct pos *pos0, struct pos *pos1) {
  if (turn0) {
    return pos0;
  }
  return pos1;
}

int main(void) {
  FILE *fp = fopen("input.txt", "r");
  if (fp == NULL) {
    perror("error opening file");
    return EXIT_FAILURE;
  }
  struct pos santa_pos = {MAX_CHARS, MAX_CHARS};
  struct pos robo_pos = {MAX_CHARS, MAX_CHARS};
  bool *seen = NULL;
  int answer = establish_map(&seen, santa_pos, fp);
  int c;
  bool santas_turn = true;

  while ((c = fgetc(fp)) != EOF) {
    struct pos *cur_pos = pick_pos(santas_turn, &santa_pos, &robo_pos);
    char_to_pos(c, cur_pos);
    answer += count_spot(*cur_pos, seen);
    santas_turn = !santas_turn;
  }

  free(seen);
  fclose(fp);
  printf("answer is %d\n", answer);
  return 0;
}
