#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct cookies {
   char type[15];
   int num;
   struct cookies *next;
};

void printcookies(struct cookies *c) {
  printf("Today, I ate %d %s cookies\n", c -> num, c -> type);
}

struct cookies * makecookies(char *t, int n, struct cookies *s) {
  struct cookies *c = malloc(sizeof(struct cookies));
  strcpy(c -> type, t);
  c -> num = n;
  c -> next = s;
  return c;
}

void print_list(struct cookies *c) {
  while (c) {
    printcookies(c);
    c = c->next;
  }
}

struct cookies * insert_front(struct cookies *c, char *t, int n) {
  struct cookies *new = makecookies(t, n, c);
  return new;
}

struct cookies * free_list(struct cookies *c) {
  struct cookies *next = c -> next;
  while (next) {
    free(c);
    c = next;
    next = c -> next;
  }
  return next;
}

int main() {
  int i = 0;
  srand(time(NULL));

  struct cookies *test = 0;
  for (i = 0; i < 3; i ++) {
    char type[15] = {rand() % 26 + 'a', rand() % 26 + 'a', rand() % 26 + 'a'};
    test = insert_front(test, type, rand() % 10);
  }
  print_list(test);

  printf("\nPrint free_list: \n");
  test = free_list(test);
  print_list(test);

  return 0;
}
