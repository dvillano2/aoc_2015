#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LINE_MAX 30

int vowel_update(char c) {
  switch (c) {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
    return 1;
  default:
    return 0;
  }
}

bool forbidden(char char0, char char1) {
  return (char0 == 'a' && char1 == 'b') || (char0 == 'c' && char1 == 'd') ||
         (char0 == 'p' && char1 == 'q') || (char0 == 'x' && char1 == 'y');
}

int score_line(const char *line) {
  if (line[0] == '\n' || line[0] == '\0') {
    return 0;
  }
  bool contains_double = false;
  bool is_forbidden = false;
  int vowels = vowel_update(line[0]);
  for (size_t i = 1; line[i] != '\n' && line[i] != '\0'; i++) {
    char c = line[i];
    char b = line[i - 1];
    vowels += vowel_update(c);
    contains_double |= b == c;
    is_forbidden |= forbidden(b, c);
  }
  return contains_double && !is_forbidden && vowels >= 3;
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
