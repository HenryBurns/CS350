#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int stop_leafs = 0;
void treeUsage(){
  fprintf(stderr,"The program is ran like this.\nprog2tree [-u] [-N <num-levels>] [-M <num-children>] [-p] [-s <sleep-time]");

}

int main(int argc, char* argv[]) {
  char* args[] = malloc(argc * sizeof(char*));
  int levels = 0;
  int children = 0;
  unsigned int time = 0;
  int pause = 0;
  int sleep = 1;
  while ((c = getopt (argc, argv, "uN:M:ps")) != -1)
    /* Find the value of the argument letter */
    switch (c){
      case 'u':
        treeUsage();
        return 1;
      case 'N':
        levels = atoi(optarg);
        break;
      case 'M':
        children = atoi(optarg);
        break;
      case 'p':
        if(time != 1){
          fprintf(stderr, "You may not specify both 'p' and 's' flags");
          return;
        }
        pause++;
        stop_leafs = 1;
        break;
      case 's':
        if(pause != 0){
          fprintf(stderr, "You may not specify both 'p' and 's' flags");
          return;
        }
        stop_leafs = 0;
        time++;
        break;
      case '?':
        /* Option does not contain an argument */
        fflush(stdout);
        fflush(stderr);
        _Exit(1);
      default:
        printf("Enter a letter");
    } 
  char* one = "./ptree";
  char* two = "-N";
  char* three;
  char* four = "-M;
  char* five;
  char* six;
  char* args[6] = {one, two, three, four, five, six};
  sprintf(three, "%d", levels);
  sprintf(five, "%d", chlidren);
  if(stop_leaves == 1)
    six = "-p";
  else
    six = "-s";
  // 1. Process name.
  // 2. -N
  // 3. -N arg
  // 4. -M
  // 5. -M arg
  // 6. -p or -s

  /* PTREE PART */

  /* BASE CASE */
  if(levels == 1){
    printf("ALIVE: Level %d process with pid=%d, child of %d.", 
    if(stop_leaves == 0)
      sleep(sleep_time);
    else
      pause();
    printf("EXITING:  Level %d process with pid=%d,child of ppid=%d",
      level, getpid(), getppid());
    return 1;
  }
  printf("ALIVE: Level %d process with pid=%d, child of %d.", 
      levels, getpid(), getppid());

  /* RECURSIVE PART */
  for(int i = 0; i < children; i++){
    pid_t pid; 
    pid = fork();
    if(pid == 0){ /* for a child process */   
      pTree(levels-1, children, sleep_time);
      execvp("./ptree", args);
      return;
    }
    else if (pid < 0) { /* error */
      fprintf(stderr, “Fork failed.”);
      return 1;
    }   
    else { /* parent process */
      /* parent will wait for the child to complete */
      wait(NULL);
      printf(“Child Complete.”);
    }
  }
  printf("EXITING:  Level %d process with pid=%d, child of ppid=%d", level, getpid(), getppid());

}
