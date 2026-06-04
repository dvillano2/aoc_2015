#include <stdio.h>
#include <stdlib.h>

#include "box.h"

int wrapping_needed(struct box box) {
  int side_1 = box.l * box.w;
  int side_2 = box.l * box.h;
  int side_3 = box.w * box.h;
  int min_side = triple_min(side_1, side_2, side_3);
  return 2 * (side_1 + side_2 + side_3) + min_side;
}

int main(void) {
  FILE *fp = fopen("input.txt", "r");
  if (fp == NULL) {
    perror("error opening the file");
    return EXIT_FAILURE;
  }
  int answer = 0;
  for (char line[20]; fgets(line, 20, fp);) {
    struct box box = line_to_box(line);
    answer += wrapping_needed(box);
  }
  fclose(fp);
  printf("answer is %d\n", answer);
  return 0;
}
