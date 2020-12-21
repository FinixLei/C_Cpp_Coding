#include "signal_handler.h"

static struct sigaction old_sigterm_info;

void signal_handler(int signo, siginfo_t * info, void * context)
{
    printf("Get Terminal Signal...\n");
    
    sigaction(signo, &old_sigterm_info, NULL);
    pid_t myself = getpid();
    kill(myself, signo);
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

    switch (signo)
    {
    case SIGTERM:
        sigaction(signo, &sigaction_info, &old_sigterm_info);
        break;
    default:
        break;
    }
}
