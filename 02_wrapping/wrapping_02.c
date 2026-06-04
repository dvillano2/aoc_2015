#include <stdio.h>
#include <stdlib.h>

#include "box.h"

int ribbon_needed(struct box box) {
  int perim_1 = box.l + box.w;
  int perim_2 = box.l + box.h;
  int perim_3 = box.w + box.h;
  int min_perim = triple_min(perim_1, perim_2, perim_3);
  return 2 * min_perim + box.l * box.w * box.h;
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
    answer += ribbon_needed(box);
  }
  fclose(fp);
  printf("answer is %d\n", answer);
  return 0;
}
