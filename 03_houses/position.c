#include "position.h"
#include <stdlib.h>

int char_to_pos(int c, struct pos *cur_pos) {
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
    return 1;
  }
  return 0;
}

int count_spot(struct pos cur_pos, bool *seen) {
  int spot = cur_pos.x + MAX_CHARS * cur_pos.y;
  if (seen[spot]) {
    return 0;
  }
  seen[spot] = true;
  return 1;
}

int establish_map(bool **seen, struct pos pos, FILE *fp) {
  *seen = calloc(2 * MAX_CHARS * 2 * MAX_CHARS, sizeof(bool));
  if (*seen == NULL) {
    fclose(fp);
    perror("error allocating memory");
    return EXIT_FAILURE;
  }
  return count_spot(pos, *seen);
}
