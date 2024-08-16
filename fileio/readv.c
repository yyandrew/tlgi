#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/uio.h>
int main(int argc, char *argv[])
{
  int fd;
  fd = open(argv[1], O_RDWR|O_APPEND);
  if (fd == -1) {
    printf("Unable to open %s\n", argv[1]);
    return 0;
  }
  char *str1 = "hello ";
  char str2[] = "world\n";
  ssize_t nwritten;
  struct iovec iov[2];
  iov[0].iov_base = str1;
  iov[0].iov_len = strlen(str1);
  iov[1].iov_base = str2;
  iov[1].iov_len = strlen(str2);
  nwritten = writev(fd, iov, 2);
  printf("Wrinte size: %ld\n", nwritten);
  return 0;
}
