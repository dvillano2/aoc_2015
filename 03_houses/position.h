#ifndef POSITION_H
#define POSITION_H

#include <stdio.h>
#include <stdbool.h>

#define MAX_CHARS 9000

struct pos{
	int x;
	int y;
};

int char_to_pos(int c, struct pos *cur_pos);
int count_spot(struct pos cur_pos, bool *seen);
int establish_map(bool **seen, struct pos pos, FILE *fp);

#endif
