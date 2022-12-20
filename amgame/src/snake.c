#include <sys/time.h>		/* for setitimer */
#include <unistd.h>		/* for pause */
#include <signal.h>		/* for signal */
#include "snake.h"
#define INTERVAL 33.3

void storyBoardTick(int signal)
{
    puts("tick");
}


// http://web.cs.wpi.edu/~claypool/courses/525-S01/samples/setitimer.c

void storyBoardRun()
{
    
    struct itimerval it_val;/* for setting itimer */
    it_val.it_interval.tv_sec = INTERVAL / 1000;
    it_val.it_interval.tv_usec = (INTERVAL *1000) % 1000000;
    it_val.it_value = it_val.it_interval;
    if(setitimer(ITIMER_REAL,&it_val,NULL) == -1)
    {
        perror("error calling setitimer()");
        exit(1);
    }
    signal(SIGALRM,storyBoardTick);
    while(1)
    {
        pause();
    }
}

