// g++ main.cpp signal_handler.cpp 

#include "signal_handler.h"

int main()
{
    set_signal_handler(SIGTERM, signal_handler);
    
    while(true) {
        sleep(1);
    }
    return 0;
}
