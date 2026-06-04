#include "position.h"
#include <stdlib.h>

void char_to_pos(int c, struct pos *cur_pos) {
  switch (c) {
  case '^':
    cur_pos->y++;
    break;
  case 'v':
    cur_pos->y--;
    break;
  case '>':
    cur_pos->x++;
    break;
  case '<':
    cur_pos->x--;
    break;
  default:
    return;
  }
}

int count_spot(struct pos cur_pos, bool *seen) {
  if (cur_pos.x < 0 || cur_pos.y < 0 || cur_pos.x >= MAP_WIDTH ||
      cur_pos.y >= MAP_HEIGHT) {
    fprintf(stderr, "Position out of bounds: (%d, %d)\n", cur_pos.x, cur_pos.y);
    exit(EXIT_FAILURE);
  }

  int spot = cur_pos.x + MAP_WIDTH * cur_pos.y;
  if (seen[spot]) {
    return 0;
  }
  seen[spot] = true;
  return 1;
}
