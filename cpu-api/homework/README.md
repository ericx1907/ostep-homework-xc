# Chapter 5 homework solution
---
* Q1. Write a program that calls `fork()`. Before calling `fork()`, have the main
process access a variable (e.g., `x`) and set its value to something (e.g., `100`).
What value is the variable in the child process? What happens to the variable when both
the child and parent change the value of `x`?

    * The value of x in the child process will have the same value as the one in parent
      process

```c
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
```
```sh
$ Parent: the value of x is 10 at 0x7ffdc17098f8, (pid: 3574845)
$ Child: the value of x is 11 at 0x7ffdc17098f8, (pid: 3574846)
$ Parent: the value of x is 12 at 0x7ffdc17098f8, (pid: 3574845)
```
    * In the code above, `x` is statically allocated (on parent process stack). `x` is
      modified in both child and parent process. As we can see in the run result
      changing `x` in child process does not affect the `x` value in parent process.
      This is because when `fork()` is called a child process is created with its own
      virtual address space including `text`, `data`, `heap` and `stack` with value
      copied from parent's address space (In reality it uses [copy-on-write][1]). The
      address spaces of child and parent are mapped onto different physical addresses
      and as a result, `x` at the same virtual address in child and parent have
      different values. 
