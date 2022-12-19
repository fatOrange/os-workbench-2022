#include <sys/time.h>		/* for setitimer */
#include <unistd.h>		/* for pause */
#include <signal.h>		/* for signal */

struct storyboard_t
{
    int interval;
    void(*update)(const struct storyboard*);

};
// http://web.cs.wpi.edu/~claypool/courses/525-S01/samples/setitimer.c

void storyBoardRun(storyboard_t* storyboard)
{
    
    struct itimerval it_val;/* for setting itimer */
    it_val.it_interval.tv_sec = storyboard->interval / 1000;
    it_val.it_interval.tv_usec = (storyboard->interval *1000) % 1000000;
    it_val.it_value = it_val.it_interval;
    if(setitimer(ITIMER_REAL,&it_val,NULL) == -1)
    {
        perror("error calling setitimer()");
        exit(1);
    }
    signal(SIGALRM,)
    while(1)
    {
        pause();
    }
}

