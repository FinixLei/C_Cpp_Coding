// g++ timer.cpp -lrt 

#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include <signal.h>
#include <unistd.h>

void CreateAndStartTimer(unsigned int wait_seconds)
{
    if (wait_seconds == 0) return; 
    
    timer_t timerid;
    struct sigevent sev;
    struct itimerspec its;
    
    // Create the timer
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGTERM;
    sev.sigev_value.sival_ptr = &timerid;
    if (timer_create(CLOCK_REALTIME, &sev, &timerid) == -1) {
        fprintf(stderr, "Failed to create timer, will continue running.\n");
        return;
    }

    // Start the timer
    its.it_value.tv_sec = wait_seconds;
    its.it_value.tv_nsec = 0;
    its.it_interval.tv_sec = 1;
    its.it_interval.tv_nsec = 0;

    if (timer_settime(timerid, 0, &its, NULL) == -1) {
        fprintf(stderr, "Failed to set timer, will continue running.\n");
    }
}


int main(int argc, char *argv[])
{
    unsigned int wait_seconds = 0;
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <time-out-seconds> \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    wait_seconds = atoi(argv[1]);
    if (wait_seconds > 0) CreateAndStartTimer(wait_seconds);

    while (1) {
        sleep(1);
    }

    return 0;
}
