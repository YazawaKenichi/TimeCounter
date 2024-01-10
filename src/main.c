#include "main.h"
#include "TimeCounter.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    const char* path = argv[1];
    TimeCounter* counter = create_time_counter(path);
    start_counter(counter);

    for(unsigned int i = 0; i < SEC; i++)
    {
        sleep(1);
    }

    stop_counter(counter);
    delete_time_counter(counter);

    return 0;
}

