#include "main.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
    const char* path = argv[1];
    //! instance
    TimeCounter* counter = create_time_counter("./text");
    //! start
    start_counter(counter);

    for(unsigned int i = 0; i < SEC; i++)
    {
        sleep(1);
    }

    //! stop
    stop_counter(counter);

    return 0;
}

