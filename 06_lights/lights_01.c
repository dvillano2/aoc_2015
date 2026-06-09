#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 1000
#define LINE_SIZE 50
enum Action {
  ON,
  OFF,
  TOGGLE,
};

struct pair {
  size_t x;
  size_t y;
};

struct location_action {
  struct pair start;
  struct pair end;
  enum Action action;
};

struct pair str_to_pair(char *s) {
  struct pair pair;
  char *endp;
  const char *runner = s;
  long x = strtol(runner, &endp, 10);
  pair.x = (size_t)x;
  runner = endp + 1;
  long y = strtol(runner, &endp, 10);
  pair.y = (size_t)y;
  return pair;
}

struct location_action parse_line(char *line) {
  struct location_action result;
  const char *delim = " \n";
  char *token = strtok(line, delim);
  if (strcmp(token, "turn") == 0) {
    token = strtok(NULL, delim);
    result.action = strcmp(token, "on") == 0 ? ON : OFF;
  } else {
    result.action = TOGGLE;
  }
  token = strtok(NULL, delim);
  result.start = str_to_pair(token);
  strtok(NULL, delim);
  token = strtok(NULL, delim);
  result.end = str_to_pair(token);
  return result;
}

void update_buf(struct location_action location_action, bool *buf) {
  size_t width = location_action.end.x - location_action.start.x;
  size_t height = location_action.end.y - location_action.start.y;
  size_t expanded_start =
      location_action.start.x + GRID_SIZE * location_action.start.y;
  enum Action action = location_action.action;
  for (size_t i = 0; i <= width; i++) {
    for (size_t j = 0; j <= height; j++) {
      size_t spot = expanded_start + i + GRID_SIZE * j;
      if (action == ON) {
        buf[spot] = true;
      } else if (action == OFF) {
        buf[spot] = false;
      } else {
        buf[spot] = !buf[spot];
      }
    }
  }
}

int main(void) {
  FILE *fp = fopen("input.txt", "r");
  if (fp == NULL) {
    perror("error opening file");
    return EXIT_FAILURE;
  }
  bool *buf = calloc(GRID_SIZE * GRID_SIZE, sizeof(bool));
  if (buf == NULL) {
    fclose(fp);
    perror("error allocating buffer");
    return EXIT_FAILURE;
  }
  char line[LINE_SIZE];
  while (fgets(line, LINE_SIZE, fp)) {
    struct location_action location_action = parse_line(line);
    update_buf(location_action, buf);
  }
  int answer = 0;
  for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
    answer += buf[i];
  }
  free(buf);
  fclose(fp);
  printf("answer is %d\n", answer);
  return 0;
}
