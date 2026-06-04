#ifndef BOX_H
#define BOX_H

struct box {
  int l;
  int w;
  int h;
};

struct box line_to_box(char *line);
int triple_min(int a, int b, int c);

#endif
