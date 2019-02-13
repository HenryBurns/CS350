#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int stop_leaves = 0;
void treeUsage(){
  fprintf(stderr,"The program is ran like this.\nprog2tree [-u] [-N <num-levels>] [-M <num-children>] [-p] [-s <sleep-time]");

}

int main(int argc, char* argv[]) {
  int levels = 0;
  int children = 0;
  unsigned int time = 0;
  int pause_state = 0;
  int sleep_time = 1;
  int c;
  while ((c = getopt (argc, argv, "uN:M:ps")) != -1){
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
          return 1;
        }
        pause_state++;
        stop_leaves = 1;
        break;
      case 's':
        if(pause_state != 0){
          fprintf(stderr, "You may not specify both 'p' and 's' flags");
          return 1;
        }
        stop_leaves = 0;
        time++;
        sleep_time = atoi(optarg);
        break;
      case '?':
        /* Option does not contain an argument */
        printf("You need an arg");
        fflush(stdout);
        fflush(stderr);
        _Exit(1);
      default:
        printf("Enter a letter");
    } 
  }
  char* one = "./ptree";
  char* two = "-N";
  char three[20];
  char* four = "-M";
  char five[20];
  char* p = "-p";
  char* s = "-s";
  sprintf(three, "%d", levels);
  sprintf(five, "%d", children);
  printf("Stop leaves: %d\n", stop_leaves);

  /** TODO p/s thing doesn't work **/
  char* args[6];
  if(stop_leaves == 1){
    char* args1[6] = {one, two, three, four, five, p};
    args = args1;
  }
  else {
    char* args1[6] = {one, two, three, four, five, s};
    args = args1;
  }
  for(int i = 0; i < 6; i++){
      printf("%s\n", args[i]);
  }
  fflush(stdout);
  printf("Ended args\n");
  // 1. Process name.
  // 2. -N
  // 3. -N arg
  // 4. -M
  // 5. -M arg
  // 6. -p or -s

  /* PTREE PART */

  /* BASE CASE */
  if(levels == 1){
    printf("Level = 1\n");
    printf("ALIVE: Level %d process with pid=%d, child of %d.",
            levels, getpid(), getppid());
    if(stop_leaves == 0)
      sleep(sleep_time);
    else
      pause();
    printf("EXITING:  Level %d process with pid=%d,child of ppid=%d",
      levels, getpid(), getppid());
    return 1;
  }
  printf("ALIVE: Level %d", levels);
  fflush(stdout);
  printf("process with pid=%d, child of", getpid());
  fflush(stdout);
  printf(" %d.", getppid());
  fflush(stdout);

  /* RECURSIVE PART */
  for(int i = 0; i < children; i++){
    pid_t pid; 
    pid = fork();
    wait(NULL);
    if(pid == 0){ /* for a child process */   
      execvp("./ptree", args);
      return 1;
    }
    else if (pid < 0) { /* error */
      fprintf(stderr, "Fork failed.");
      return 1;
    }   
    else { /* parent process */
      /* parent will wait for the child to complete */
      printf("Child Complete.");
    }
  }
  printf("EXITING:  Level %d process with pid=%d, child of ppid=%d", levels, getpid(), getppid());

}
