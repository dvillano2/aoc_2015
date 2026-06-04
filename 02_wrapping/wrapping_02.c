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

int ribbon_needed(struct box box) {
  int perim_1 = box.l + box.w;
  int perim_2 = box.l + box.h;
  int perim_3 = box.w + box.h;
  int min_perim = triple_min(perim_1, perim_2, perim_3);
  return 2 * min_perim + box.l * box.w * box.h;
}

int main(void) {
  FILE *fp = fopen("input.txt", "r");
  int answer = 0;
  for (char line[20]; fgets(line, 20, fp);) {
    struct box box = line_to_box(line);
    answer += ribbon_needed(box);
  }
  fclose(fp);
  printf("answer is %d\n", answer);
  return 0;
}
