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

struct cookies * makecookies(char *t, int n) {
  struct cookies *c = malloc(sizeof(struct cookies));
  strcpy(c -> type, t);
  c -> num = n;
  return c;
}

void print_list(struct cookies *c) {
  while (c) {
    printcookies(c);
    c = c->next;
  }
}

int main() {
  int i = 0;
  srand(time(NULL));
  for (i = 0; i < 3; i ++) {
    char type[15] = {'h', 'i'};
    struct cookies *c = makecookies(type, 3);
    // printcookies(c);
    free(c);
  }

  struct cookies *test;
  for (i = 0; i < 3; i ++) {
    char type[15] = {'b'};
    struct cookies *test = makecookies(type, rand() % 10);
    print_list(test);
    free(test);
  }


  return 0;
}
