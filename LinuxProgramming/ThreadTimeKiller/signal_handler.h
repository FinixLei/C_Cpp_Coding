#ifndef SIGNAL_HANDLER_H
#define SIGNAL_HANDLER_H

#include <signal.h>
#include <unistd.h>

#include <cstdlib>
#include <cstdio>
#include <cstring>


typedef void (*signal_handler_t) (int, siginfo_t *, void *);

void signal_handler(int signo, siginfo_t * info, void * context);

void set_signal_handler(int signo, signal_handler_t handler);


#endif