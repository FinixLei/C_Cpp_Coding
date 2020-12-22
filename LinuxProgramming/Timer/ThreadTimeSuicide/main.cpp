// g++ main.cpp signal_handler.cpp -lpthread

// This program is to start one thread,
// in which it repeats to sleep 1 second then check if expired.


#include <ctime>
#include <pthread.h>
#include "signal_handler.h"

void * timer_func(void * arg)
{
    int wait_seconds = *((int *)arg);
    
    time_t beg = time(0);
    time_t end = beg; 
    
    int count = 0;
    while(true) {
        sleep(1);
        
        end = time(0);
        
        if (end-beg >= wait_seconds) {
            printf("%d seconds passed\n", (end-beg));
            break;
        }
    }

    pid_t myself = getpid();
    kill(myself, SIGTERM);
    
    return 0;
}

int main()
{
    set_signal_handler(SIGTERM, signal_handler);
    
    int wait_seconds = 5; 
    
    pthread_t timer_tid;
    int err = pthread_create(&timer_tid, NULL, timer_func, &wait_seconds);
    
    if (err != 0) {
        printf("Cannot create timer thread\n");
        exit(1);
    }
    
    while(true) {
        sleep(1);
    }
    return 0;
}

