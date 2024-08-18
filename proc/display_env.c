#include <stdlib.h>
#include <stdio.h>
#include <time.h>
extern char **environ;
int main(int argc, char *argv[])
{
  char **ep;
  for (ep = environ; *ep != NULL; ep++) {
    printf("environ: %s\n", *ep);
  }
  char *hp;
  hp = getenv("http_proxy");
  printf("http_proxy: %s\n", hp);
  return 0;
}
