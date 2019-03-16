#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread> 

void thread_task(int tid) {
    char buf[30];
    sprintf(buf, "thread %d: %x\n", tid, std::this_thread::get_id());
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << buf;
}

int main(int argc, char *argv[]) {
    const int size = 10;
    std::thread * tarray[size];

    for (int i = 0; i < size; ++i) {
        tarray[i] = new std::thread(thread_task, i);
    }

    for (auto t : tarray) {
        t->join();
    }

    return EXIT_SUCCESS;
}

/**! Output as below:
thread 0: 10520
thread 7: 10ec0
thread 8: 11020
thread 4: 10aa0
thread 9: 11180
thread 5: 10c00
thread 6: 10d60
thread 3: 10940
thread 1: 10680
thread 2: 107e0
**/
