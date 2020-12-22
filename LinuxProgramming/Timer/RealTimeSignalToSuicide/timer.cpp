// g++ timer.cpp -lrt 

#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include <signal.h>
#include <unistd.h>

#define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); } while (0)

#define SIG SIGRTMIN


typedef void (*signal_handler_t) (int, siginfo_t *, void *);

void signal_handler(int signo, siginfo_t * info, void * context)
{
    pid_t myself = getpid();
    kill(myself, SIGTERM);
}


void set_signal_handler(int signo, signal_handler_t handler)
{
    struct sigaction sigaction_info;
    memset(&sigaction_info, 0, sizeof(sigaction_info));
    
    sigset_t sigset_info;
    sigemptyset(&sigset_info);
    
    sigaction_info.sa_handler = NULL;
    sigaction_info.sa_sigaction = handler;
    sigaction_info.sa_mask = sigset_info;
    sigaction_info.sa_flags = SA_SIGINFO;
}

void CreateAndStartTimer(unsigned int wait_seconds)
{
    timer_t timerid;
    struct sigevent sev;
    struct itimerspec its;
    sigset_t mask;
    
    // Block timer signal temporarily
    sigemptyset(&mask);
    sigaddset(&mask, SIG);
    if (sigprocmask(SIG_SETMASK, &mask, NULL) == -1) {
        errExit("sigprocmask");
    }
    
    // Create the timer
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIG;
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
    
    // Unblock timer signal 
    if (sigprocmask(SIG_UNBLOCK, &mask, NULL) == -1) {
        errExit("sigprocmask");
    }
}


int main(int argc, char *argv[])
{
    unsigned int wait_seconds = 0;
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <time-out-secs> \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    wait_seconds = atoi(argv[1]);
    set_signal_handler(SIG, signal_handler);
    
    if (wait_seconds > 0) CreateAndStartTimer(wait_seconds);

    while (1) {
        sleep(1);
    }

    exit(EXIT_SUCCESS);
}
