struct cookies {
   char type[15];
   int num;
   struct cookies *next;
};

void printcookies(struct cookies *c);

struct cookies * makecookies(char *t, int n, struct cookies *s);

void print_list(struct cookies *c);

struct cookies * insert_front(struct cookies *c, char *t, int n);

struct cookies * free_list(struct cookies *c);

struct cookies * remove_cookies(struct cookies *front, char *t, int n);
