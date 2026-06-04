#include <stdio.h>

struct box {
  int l;
  int w;
  int h;
};

struct box line_to_box(char line[20]) {
  int l = 0;
  int w = 0;
  int h = 0;
  for (; *line != 'x'; line++) {
    l = 10 * l + *line - '0';
  }
  line++;
  for (; *line != 'x'; line++) {
    w = 10 * w + *line - '0';
  }
  line++;
  for (; *line != '\n'; line++) {
    h = 10 * h + *line - '0';
  }
  struct box box = {l, w, h};
  return box;
}

int triple_min(int a, int b, int c) {
  int first_min = a < b ? a : b;
  return c < first_min ? c : first_min;
}

int wrapping_needed(struct box box) {
  int side_1 = box.l * box.w;
  int side_2 = box.l * box.h;
  int side_3 = box.w * box.h;
  int min_side = triple_min(side_1, side_2, side_3);
  return 2 * (side_1 + side_2 + side_3) + min_side;
}

int main(void) {
  FILE *fp = fopen("input.txt", "r");
  int answer = 0;
  for (char line[20]; fgets(line, 20, fp);) {
    struct box box = line_to_box(line);
    answer += wrapping_needed(box);
  }
  fclose(fp);
  printf("answer is %d\n", answer);
  return 0;
}
