#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  int num = 10;
  int *x = &num;
  printf("Parent: the value of x is %d at %p, (pid: %d)\n",
         *x, x, (int) getpid());

  int rc = fork();
  if (rc < 0) {
    printf("fork failed :(\n");
    exit(1);
  } else if (rc == 0) {
    *x = *x+1;
    printf("Child: the value of x is %d at %p, (pid: %d)\n",
           *x, x, (int) getpid());
  } else {
    wait(NULL);
    *x = *x+2;
    printf("Parent: the value of x is %d at %p, (pid: %d)\n",
           *x, x, (int) getpid());
  }
  return 0;
}
