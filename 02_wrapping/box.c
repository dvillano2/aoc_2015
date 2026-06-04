#include "box.h"

struct box line_to_box(char *line) {
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
  for (; *line && *line != '\n'; line++) {
    h = 10 * h + *line - '0';
  }
  struct box box = {l, w, h};
  return box;
}

int triple_min(int a, int b, int c) {
  int first_min = a < b ? a : b;
  return c < first_min ? c : first_min;
}

