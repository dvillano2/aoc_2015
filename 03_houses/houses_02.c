#include <stdlib.h>

#include "position.h"

int main(void) {
  FILE *fp = fopen("input.txt", "r");
  if (fp == NULL) {
    perror("error opening file");
    return EXIT_FAILURE;
  }
  struct pos santa_pos = {MAX_CHARS, MAX_CHARS};
  struct pos robo_pos = {MAX_CHARS, MAX_CHARS};
  bool *seen = calloc(MAP_WIDTH * MAP_HEIGHT, sizeof(bool));

  if (seen == NULL) {
    fclose(fp);
    perror("error allocating memory");
    return EXIT_FAILURE;
  }

  int answer = count_spot(santa_pos, seen);
  int c;
  bool santas_turn = true;

  while ((c = fgetc(fp)) != EOF) {
    struct pos *cur_pos = santas_turn ? &santa_pos : &robo_pos;
    char_to_pos(c, cur_pos);
    answer += count_spot(*cur_pos, seen);
    santas_turn = !santas_turn;
  }

  free(seen);
  fclose(fp);
  printf("answer is %d\n", answer);
  return 0;
}
