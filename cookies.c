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

struct cookies * remove_cookies(struct cookies *front, char *t, int n) {
  struct cookies *start = front;
  struct cookies *temp = front -> next;

  if (!strcmp(front -> type, t) && front -> num == n) {
    return temp;
  }

  while (temp) {
    if (!strcmp(temp -> type, t) && temp -> num == n) {
      front -> next = temp -> next;
      break;
    }
    front = temp;
    temp = temp -> next;
  }
  return start;
}
