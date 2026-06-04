#ifndef POSITION_H
#define POSITION_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_CHARS 9000
#define MAP_WIDTH (2 * MAX_CHARS)
#define MAP_HEIGHT (2 * MAX_CHARS)

struct pos {
  int x;
  int y;
};

void char_to_pos(int c, struct pos *cur_pos);
int count_spot(struct pos cur_pos, bool *seen);

#endif
