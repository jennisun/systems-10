#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "cookies.h"

int main() {
  int i = 0;
  srand(time(NULL));

  struct cookies *test = 0;
  char type3[3] = {'i', 'j'};
  test = insert_front(test, type3, 1000);

  for (i = 0; i < 2; i ++) {
    char type2[15] = {rand() % 26 + 'a', rand() % 26 + 'a', rand() % 26 + 'a'};
    test = insert_front(test, type2, rand() % 10);
  }
  char type[3] = {'h', 'e'};
  test = insert_front(test, type, 999);

  for (i = 0; i < 2; i ++) {
    char type2[15] = {rand() % 26 + 'a', rand() % 26 + 'a', rand() % 26 + 'a'};
    test = insert_front(test, type2, rand() % 10);
  }

  char type1[3] = {'w', 'r'};
  test = insert_front(test, type1, 888);

  printf("\n-----Remove from front:-----\n");

  printf("Original: \n");
  print_list(test);

  printf("\nRemoved: \n");
  test = remove_cookies(test, type1, 888);
  printf("\n");
  print_list(test);


  printf("\n\n-----Remove from middle:-----\n");

  printf("Original: \n");
  print_list(test);

  printf("\nRemoved: \n");
  test = remove_cookies(test, type, 999);
  printf("\n");
  print_list(test);

  printf("\n\n-----Remove from end:-----\n");

  printf("Original: \n");
  print_list(test);

  printf("\nRemoved: \n");
  test = remove_cookies(test, type3, 1000);
  printf("\n");
  print_list(test);


  printf("\n\n-----Remove nonexistent value:-----\n");

  printf("Original: \n");
  print_list(test);

  printf("\nRemoved: \n");
  test = remove_cookies(test, type3, 1000);
  printf("\n");
  print_list(test);


  printf("\nPrint free_list: \n");
  test = free_list(test);
  print_list(test);

  return 0;
}
