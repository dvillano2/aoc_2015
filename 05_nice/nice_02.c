#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LINE_MAX 30

int get_spot(char b, char c) { return (b - 'a') + 26 * (c - 'a'); }

int score_line(const char *line) {
  if (line[0] == '\n' || line[0] == '\0') {
    return 0;
  }
  if (line[1] == '\n' || line[1] == '\0') {
    return 0;
  }
  bool has_alternator = false;
  bool has_two_doubles = false;
  int double_tracker[26 * 26] = {0};
  double_tracker[get_spot(line[0], line[1])] = 1;
  for (size_t i = 2; line[i] != '\n' && line[i] != '\0'; i++) {
    int a = line[i - 2];
    int b = line[i - 1];
    int c = line[i];
    int spot = get_spot(b, c);
    double_tracker[spot]++;
    has_two_doubles |= double_tracker[spot] > 2;
    has_two_doubles |= double_tracker[spot] > 1 && ((a != b) || (b != c));
    has_alternator |= a == c;
  }
  return has_alternator && has_two_doubles;
}

int main(void) {
  FILE *fp = fopen("input.txt", "r");
  if (fp == NULL) {
    perror("error opening file");
    return EXIT_FAILURE;
  }
  int answer = 0;
  char line[LINE_MAX];
  while (fgets(line, sizeof(line), fp)) {
    answer += score_line(line);
  }
  fclose(fp);
  printf("answer is %d\n", answer);
  return 0;
}
