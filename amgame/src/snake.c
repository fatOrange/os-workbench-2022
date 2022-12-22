#include <sys/time.h>		/* for setitimer */
#include <unistd.h>		/* for pause */
#include <signal.h>		/* for signal */
#include "snake.h"
#define INTERVAL 33
#include <time.h>
void storyBoardTick(int signal)
{
    puts("tick");
}


// http://web.cs.wpi.edu/~claypool/courses/525-S01/samples/setitimer.c

void storyBoardRun()
{
    while(1)
    {

    }

}

