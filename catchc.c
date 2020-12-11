#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void INThandler(int sig)
{
  char c;
  signal(sig, SIG_IGN);
  printf("OUCH, did you hit Ctrl-C?\nDo you really want to quit? [y/n] ");
  c = getchar();
  if (c == 'y' || c == 'Y')
    exit(0);
  else if (c == 'n' || c == 'N')
    signal(SIGINT, INThandler);
  else {
    printf("Invaid input. Go back to sleep\n");
    signal(SIGINT, INThandler);
  }

  getchar(); // Get new line character
}

int main(void)
{
  signal(SIGINT, INThandler);
  while (1) {_sleep(1);}
  return 0;
}
