#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "cookies.h"

int main() {
  int i = 0;
  srand(time(NULL));

  struct cookies *test = 0;
  for (i = 0; i < 3; i ++) {
    char type2[15] = {rand() % 26 + 'a', rand() % 26 + 'a', rand() % 26 + 'a'};
    test = insert_front(test, type2, rand() % 10);
  }
  char type[3] = {'h', 'e'};
  test = insert_front(test, type, 2);

  char type1[3] = {'w', 'r'};
  test = insert_front(test, type1, rand() % 10);

  print_list(test);

  printf("\n");
  test = remove_cookies(test, type, 2);
  printf("\n");
  print_list(test);

  printf("\nPrint free_list: \n");
  test = free_list(test);
  print_list(test);

  return 0;
}
